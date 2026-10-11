/*
 * SHLOK // ROBOTICS & NEURO-METROLOGY
 * Project: F1 Grand Prix Reaction Timer (with Live Wiring Feedback)
 *
 * Hardware Map:
 *   - Pin 10: Green LED Anode (+) via 220Ω
 *   - Pin 12: Red LED Anode (+) via 220Ω
 *   - Pin 2 : Tactile Push Button (to GND, INPUT_PULLUP)
 *
 * Feature:
 *   - STAGE 1 (WIRING CHECK): Alternates Green and Red continuously!
 *     As soon as you plug each LED in correctly, you will see it blinking!
 *   - STAGE 2 (THE RACE): Press the button once to start the F1 reaction game!
 */

#include <Arduino.h>

constexpr uint8_t PIN_BUTTON   = 2;
constexpr uint8_t PIN_LED_GREEN = 10;
constexpr uint8_t PIN_LED_RED   = 12;

enum class GameState : uint8_t {
    WIRING_TEST_BLINK, // Continuously alternates LEDs so you know wiring is good
    ARMING,            // Red solid ON ("Get ready...")
    WAITING_FOR_GREEN, // Random delay (2-5s) + false start check
    TIMING_REACTION,   // Green slams ON, measuring ms
    SHOW_RESULT        // Display score
};

GameState currentState = GameState::WIRING_TEST_BLINK;

unsigned long lastBlinkTime = 0;
bool toggleState = false;
unsigned long stateStartTime = 0;
unsigned long randomWaitDuration = 0;
unsigned long greenTurnOnTime = 0;

void evaluateScore(unsigned long reactionMs) {
    Serial.println(F("\n---------------------------------------------------"));
    Serial.print(F(">>> REACTION TIME: "));
    Serial.print(reactionMs);
    Serial.println(F(" MILLISECONDS <<<"));

    if (reactionMs < 185) {
        Serial.println(F(">>> TIER: GODLIKE // F1 WORLD CHAMPION (VERSTAPPEN TIER)"));
    } else if (reactionMs < 230) {
        Serial.println(F(">>> TIER: TOP GUN // FIGHTER JET PILOT / ESPORTS PRO"));
    } else if (reactionMs < 290) {
        Serial.println(F(">>> TIER: STANDARD // AVERAGE HUMAN REACTION"));
    } else {
        Serial.println(F(">>> TIER: BRAIN LAG // SLEEPY ZOMBIE / DRINK SOME WATER"));
    }
    Serial.println(F("---------------------------------------------------"));
    Serial.println(F("Next round starting in 3 seconds...\n"));
}

void triggerFalseStart() {
    Serial.println(F("\n[!] FALSE START! You jumped before Green! Disqualified!"));
    for (int i = 0; i < 5; ++i) {
        digitalWrite(PIN_LED_RED, HIGH);
        delay(70);
        digitalWrite(PIN_LED_RED, LOW);
        delay(70);
    }
    delay(1000);
    currentState = GameState::ARMING;
}

void setup() {
    Serial.begin(115200);
    while (!Serial && millis() < 2000) {}

    pinMode(PIN_BUTTON, INPUT_PULLUP);
    pinMode(PIN_LED_GREEN, OUTPUT);
    pinMode(PIN_LED_RED, OUTPUT);

    randomSeed(analogRead(A5));

    Serial.println(F("\n========================================================"));
    Serial.println(F("[SYSTEM]: F1 REACTION BENCHMARK ONLINE                  "));
    Serial.println(F("[STATUS]: WIRING CHECK MODE ACTIVE                      "));
    Serial.println(F("Green and Red will alternate blink every 300ms.         "));
    Serial.println(F("When your wiring is ready, PRESS THE BUTTON to start!   "));
    Serial.println(F("========================================================"));
}

void loop() {
    switch (currentState) {
        case GameState::WIRING_TEST_BLINK:
            // Blink Green and Red alternately so user has live feedback while plugging wires!
            if (millis() - lastBlinkTime >= 300) {
                lastBlinkTime = millis();
                toggleState = !toggleState;
                digitalWrite(PIN_LED_GREEN, toggleState ? HIGH : LOW);
                digitalWrite(PIN_LED_RED, toggleState ? LOW : HIGH);
            }

            // Once the button is plugged in and pressed, start the game!
            if (digitalRead(PIN_BUTTON) == LOW) {
                delay(50); // Debounce
                if (digitalRead(PIN_BUTTON) == LOW) {
                    digitalWrite(PIN_LED_GREEN, LOW);
                    digitalWrite(PIN_LED_RED, LOW);
                    Serial.println(F("\n[+] BUTTON VERIFIED! STARTING F1 RACE IN 1 SECOND..."));
                    delay(1000);
                    currentState = GameState::ARMING;
                }
            }
            break;

        case GameState::ARMING:
            digitalWrite(PIN_LED_GREEN, LOW);
            digitalWrite(PIN_LED_RED, HIGH); // Red solid ON = "Get Ready"

            Serial.println(F("[GRID ARMED] Red Light is ON. Hover finger on button..."));
            randomWaitDuration = random(2000, 5000);
            stateStartTime = millis();
            currentState = GameState::WAITING_FOR_GREEN;
            break;

        case GameState::WAITING_FOR_GREEN:
            // False Start Detection
            if (digitalRead(PIN_BUTTON) == LOW) {
                triggerFalseStart();
                return;
            }

            if (millis() - stateStartTime >= randomWaitDuration) {
                // LIGHTS OUT!
                digitalWrite(PIN_LED_RED, LOW);
                digitalWrite(PIN_LED_GREEN, HIGH);
                greenTurnOnTime = millis();
                currentState = GameState::TIMING_REACTION;
            }
            break;

        case GameState::TIMING_REACTION:
            if (digitalRead(PIN_BUTTON) == LOW) {
                unsigned long reactionMs = millis() - greenTurnOnTime;
                evaluateScore(reactionMs);

                stateStartTime = millis();
                currentState = GameState::SHOW_RESULT;
            }
            break;

        case GameState::SHOW_RESULT:
            if (millis() - stateStartTime >= 3000) {
                currentState = GameState::ARMING;
            }
            break;
    }
}
