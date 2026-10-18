/*
 * SHLOK // EMBEDDED SYSTEMS & HARDWARE INTERACTION
 * Project: SHLOK-OS // Two-Way Interactive Serial Command Shell (CLI v1.0)
 * 
 * Hardware Map (Zero Rewiring - Uses Existing Circuit 05C):
 *   - Pin 10: Blue / Green LED (Actuator 1, via 220Ω)
 *   - Pin 12: Red LED (Actuator 2, via 220Ω)
 *   - Pin 2 : Tactile Push Button (Sensor 1, INPUT_PULLUP)
 *   - Pin A0: Analog Telemetry Pin
 * 
 * Architecture:
 *   - Non-blocking ASCII Command Parser
 *   - Two-Way Telemetry & Actuation Terminal (115200 Baud)
 *   - Embedded CPU Benchmarking & Telemetry Metrics
 */

#include <Arduino.h>

constexpr uint8_t PIN_BUTTON   = 2;
constexpr uint8_t PIN_LED_BLUE = 10;
constexpr uint8_t PIN_LED_RED  = 12;

String inputBuffer = "";

void printPrompt() {
    Serial.print(F("\nSHLOK-OS> "));
}

void printBanner() {
    Serial.println(F("\n=========================================================="));
    Serial.println(F("         SHLOK-OS // HARDWARE COMMAND TERMINAL v1.0       "));
    Serial.println(F("   Two-Way Microcontroller Shell (ATmega328P @ 16 MHz)    "));
    Serial.println(F("=========================================================="));
    Serial.println(F("Type 'HELP' for available hardware commands."));
    printPrompt();
}

void runF1Race() {
    Serial.println(F("\n[!] ================= F1 RACE INITIALIZED ================="));
    Serial.println(F("[!] STAGE: RED ON. Get your finger hovering on the button!"));
    digitalWrite(PIN_LED_BLUE, LOW);
    digitalWrite(PIN_LED_RED, HIGH);

    unsigned long waitTime = random(2000, 5000);
    unsigned long startWait = millis();

    // Check false start during random delay
    while (millis() - startWait < waitTime) {
        if (digitalRead(PIN_BUTTON) == LOW) {
            Serial.println(F("[!] FALSE START! You jumped the gun! DISQUALIFIED!"));
            for (int i = 0; i < 4; ++i) {
                digitalWrite(PIN_LED_RED, HIGH);
                delay(60);
                digitalWrite(PIN_LED_RED, LOW);
                delay(60);
            }
            return;
        }
    }

    // LIGHTS OUT!
    digitalWrite(PIN_LED_RED, LOW);
    digitalWrite(PIN_LED_BLUE, HIGH);
    unsigned long goTime = millis();
    Serial.println(F("[!] LIGHTS OUT! SMASH THE BUTTON NOW!"));

    while (digitalRead(PIN_BUTTON) == HIGH) {
        // Wait for smash
    }

    unsigned long reactionMs = millis() - goTime;
    Serial.print(F("\n>>> REACTION TIME: "));
    Serial.print(reactionMs);
    Serial.println(F(" MILLISECONDS <<<"));

    if (reactionMs < 185) {
        Serial.println(F(">>> TIER: GODLIKE // F1 WORLD CHAMPION (VERSTAPPEN TIER)"));
    } else if (reactionMs < 230) {
        Serial.println(F(">>> TIER: TOP GUN // FIGHTER JET PILOT / ESPORTS PRO"));
    } else {
        Serial.println(F(">>> TIER: HUMAN // SOLID REACTION TIME"));
    }

    delay(1000);
    digitalWrite(PIN_LED_BLUE, LOW);
}

void runCpuBenchmark() {
    Serial.println(F("\n[BENCHMARK] Executing 100,000 integer math operations..."));
    unsigned long startTime = micros();

    volatile long sum = 0;
    for (long i = 0; i < 100000; ++i) {
        sum += (i * 3) / 2;
    }

    unsigned long elapsedMicros = micros() - startTime;
    float elapsedMs = elapsedMicros / 1000.0f;

    Serial.print(F("[BENCHMARK COMPLETED] Time: "));
    Serial.print(elapsedMicros);
    Serial.print(F(" microseconds ("));
    Serial.print(elapsedMs, 2);
    Serial.println(F(" ms)"));
    Serial.print(F("[COMPUTE RATE] ~"));
    Serial.print((100000.0f / elapsedMs) * 1000.0f, 0);
    Serial.println(F(" ops/sec at 16 MHz silicon clock."));
}

void printSystemStatus() {
    Serial.println(F("\n----------------- SYSTEM TELEMETRY -----------------"));
    Serial.print(F("• Uptime:        "));
    Serial.print(millis() / 1000);
    Serial.println(F(" seconds"));

    Serial.print(F("• Red LED (D12): "));
    Serial.println(digitalRead(PIN_LED_RED) ? F("ACTIVE (HIGH)") : F("OFF (LOW)"));

    Serial.print(F("• Blue LED (D10):"));
    Serial.println(digitalRead(PIN_LED_BLUE) ? F("ACTIVE (HIGH)") : F("OFF (LOW)"));

    Serial.print(F("• Button (D2):   "));
    Serial.println((digitalRead(PIN_BUTTON) == LOW) ? F("PRESSED (LOW)") : F("RELEASED (HIGH)"));

    Serial.print(F("• Analog A0 Raw: "));
    Serial.print(analogRead(A0));
    Serial.print(F(" ("));
    Serial.print((analogRead(A0) * 5.0f) / 1023.0f, 2);
    Serial.println(F(" Volts)"));
    Serial.println(F("---------------------------------------------------"));
}

void processCommand(String cmd) {
    cmd.trim();
    cmd.toUpperCase();

    if (cmd.length() == 0) {
        printPrompt();
        return;
    }

    Serial.println(cmd); // Echo command

    if (cmd == "HELP") {
        Serial.println(F("\nAVAILABLE HARDWARE COMMANDS:"));
        Serial.println(F("  RED ON      - Turn Red LED ON"));
        Serial.println(F("  RED OFF     - Turn Red LED OFF"));
        Serial.println(F("  BLUE ON     - Turn Blue LED ON"));
        Serial.println(F("  BLUE OFF    - Turn Blue LED OFF"));
        Serial.println(F("  ALL ON      - Turn both LEDs ON"));
        Serial.println(F("  ALL OFF     - Turn both LEDs OFF"));
        Serial.println(F("  TOGGLE      - Invert current state of both LEDs"));
        Serial.println(F("  STROBE      - Rapidly flash LEDs 5 times"));
        Serial.println(F("  STATUS      - Print full live hardware telemetry"));
        Serial.println(F("  BENCH       - Run ATmega328P CPU benchmark"));
        Serial.println(F("  F1          - Trigger F1 reaction reflex test"));
        Serial.println(F("  PING        - Latency check (returns PONG)"));
        Serial.println(F("  CLEAR       - Clear terminal screen"));
    } 
    else if (cmd == "RED ON") {
        digitalWrite(PIN_LED_RED, HIGH);
        Serial.println(F("[ACK] Red LED activated."));
    } 
    else if (cmd == "RED OFF") {
        digitalWrite(PIN_LED_RED, LOW);
        Serial.println(F("[ACK] Red LED deactivated."));
    } 
    else if (cmd == "BLUE ON" || cmd == "GREEN ON") {
        digitalWrite(PIN_LED_BLUE, HIGH);
        Serial.println(F("[ACK] Blue LED activated."));
    } 
    else if (cmd == "BLUE OFF" || cmd == "GREEN OFF") {
        digitalWrite(PIN_LED_BLUE, LOW);
        Serial.println(F("[ACK] Blue LED deactivated."));
    } 
    else if (cmd == "ALL ON") {
        digitalWrite(PIN_LED_RED, HIGH);
        digitalWrite(PIN_LED_BLUE, HIGH);
        Serial.println(F("[ACK] All actuators illuminated."));
    } 
    else if (cmd == "ALL OFF") {
        digitalWrite(PIN_LED_RED, LOW);
        digitalWrite(PIN_LED_BLUE, LOW);
        Serial.println(F("[ACK] All actuators darkened."));
    } 
    else if (cmd == "TOGGLE") {
        digitalWrite(PIN_LED_RED, !digitalRead(PIN_LED_RED));
        digitalWrite(PIN_LED_BLUE, !digitalRead(PIN_LED_BLUE));
        Serial.println(F("[ACK] Actuator states inverted."));
    } 
    else if (cmd == "STROBE") {
        Serial.println(F("[ACK] Executing hardware strobe sequence..."));
        for (int i = 0; i < 5; ++i) {
            digitalWrite(PIN_LED_RED, HIGH);
            digitalWrite(PIN_LED_BLUE, LOW);
            delay(80);
            digitalWrite(PIN_LED_RED, LOW);
            digitalWrite(PIN_LED_BLUE, HIGH);
            delay(80);
        }
        digitalWrite(PIN_LED_BLUE, LOW);
        Serial.println(F("[ACK] Strobe completed."));
    } 
    else if (cmd == "STATUS") {
        printSystemStatus();
    } 
    else if (cmd == "BENCH") {
        runCpuBenchmark();
    } 
    else if (cmd == "F1") {
        runF1Race();
    } 
    else if (cmd == "PING") {
        Serial.println(F("PONG! [Hardware Link: OK (115200 Baud)]"));
    } 
    else if (cmd == "CLEAR") {
        for (int i = 0; i < 35; ++i) Serial.println();
        printBanner();
        return;
    } 
    else {
        Serial.print(F("[ERR] Unknown command: '"));
        Serial.print(cmd);
        Serial.println(F("'. Type 'HELP' for command index."));
    }

    printPrompt();
}

void setup() {
    Serial.begin(115200);
    while (!Serial && millis() < 2000) {}

    pinMode(PIN_BUTTON, INPUT_PULLUP);
    pinMode(PIN_LED_BLUE, OUTPUT);
    pinMode(PIN_LED_RED, OUTPUT);

    digitalWrite(PIN_LED_BLUE, LOW);
    digitalWrite(PIN_LED_RED, LOW);

    randomSeed(analogRead(A5));
    printBanner();
}

void loop() {
    while (Serial.available() > 0) {
        char c = (char)Serial.read();

        if (c == '\n' || c == '\r') {
            if (inputBuffer.length() > 0) {
                processCommand(inputBuffer);
                inputBuffer = "";
            }
        } else {
            // Buffer characters
            if (inputBuffer.length() < 64) {
                inputBuffer += c;
            }
        }
    }
}
