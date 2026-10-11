#include <iostream>
#include <string>
#include <thread>
#include <chrono>

#ifdef _WIN32
#include <windows.h>
#endif

// Pure ANSI Color Codes
#define RESET        "\033[0m"
#define BOLD         "\033[1m"
#define DIM          "\033[2m"
#define MOUNTAIN     "\033[38;5;153m" // Soft alpine slate blue
#define SNOW         "\033[38;5;255m" // Crisp snow white
#define FOREST       "\033[38;5;71m"  // Pine emerald green
#define RIVER        "\033[38;5;75m"  // Gentle glacier river blue
#define GOLD         "\033[38;5;220m" // Medieval candlelit gold
#define EARTH        "\033[38;5;179m" // Warm rustic parchment
#define MIST         "\033[38;5;248m" // Soft valley mist grey

void sleepMs(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void configureWindowsTerminal() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE) {
        DWORD dwMode = 0;
        if (GetConsoleMode(hOut, &dwMode)) {
            dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
            SetConsoleMode(hOut, dwMode);
        }
    }
#endif
}

void printWhisper(const std::string& thought) {
    std::cout << std::endl;
    std::cout << MIST << "    ~ " << thought << " ~" << RESET << std::endl;
    sleepMs(500);
    std::cout << std::endl;
}

int main() {
    configureWindowsTerminal();

    char q_specs, q_name_letter, q_habit;
    std::string sport;

    // =========================================================================
    // PURE ASCII SWISS ALPS & GLACIER RIVER LANDSCAPE (ZERO CODE-PAGE BUGS)
    // =========================================================================
    std::cout << SNOW;
    std::cout << R"(
                 /\                                            /\
                /  \                  /\                      /  \
               / /\ \                /  \                    / /\ \
              / /  \ \    /\        /    \                  / /  \ \
             / /    \ \  /  \      /  /\  \                / /    \ \
            / /      \/   \  \    /  /  \  \              / /      \ \
           / /   /\   \ /\ \  \  /  /    \  \            / /   /\   \ \
)" << MOUNTAIN << R"(          /_/__ /  \___\/  \_/_\/__/______\__\__________/_/__ /  \___\_\
)" << FOREST << R"(             /\                  /~~~~~~~~~~~~\                 /\
            /  \                / ~ ~ ~ ~ ~ ~  \               /  \
           //\\/\              / ~ ~ ~ ~ ~ ~ ~  \             //\\/\
          ///\\\/\            / ~ ~ ~ ~ ~ ~ ~ ~  \           ///\\\/\
)" << RIVER << R"(      ~~~~~~~~~~~~~~~~~~~~~~~/ ~ ~ ~ ~ ~ ~ ~ ~ ~  \~~~~~~~~~~~~~~~~~~~~~~~~~~
                            / ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  \
)" << RESET << std::endl;

    // Pure ASCII Medieval Title
    std::cout << GOLD << BOLD << R"(
        +============================================================+
        |                 THE ANCIENT ALPINE ORACLE                  |
        |          "Where the whisper of pines reveals all"          |
        +============================================================+
)" << RESET << std::endl;

    sleepMs(400);

    // =========================================================================
    // LEVEL 1: General & Natural (Everyday Visual Biometrics)
    // =========================================================================
    std::cout << EARTH << "+-- [ INQUIRY I : THE CLEAR SIGHT ] -----------------------------------+" << RESET << std::endl;
    std::cout << "| In daily life, do you wear spectacles or optical glasses? (y/n)      |" << std::endl;
    std::cout << EARTH << "+----------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "> Your Answer: " << RESET;
    std::cin >> q_specs;

    printWhisper("A soft ripple passes over the glacier stream...");

    // =========================================================================
    // LEVEL 2: Slightly More Personal (The First Rune / Alphabet)
    // =========================================================================
    std::cout << MOUNTAIN << "+-- [ INQUIRY II : THE FIRST INITIAL ] --------------------------------+" << RESET << std::endl;
    std::cout << "| Does your given first name begin with the letter 'S' or 'J'? (y/n)   |" << std::endl;
    std::cout << MOUNTAIN << "+----------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "> Your Answer: " << RESET;
    std::cin >> q_name_letter;

    printWhisper("The mountain breeze shifts through the high valley pines...");

    // =========================================================================
    // LEVEL 3: Deeply Personal (Athletic & Physical Passion)
    // =========================================================================
    std::cout << FOREST << "+-- [ INQUIRY III : THE SPIRIT OF MOTION ] ----------------------------+" << RESET << std::endl;
    std::cout << "| Which discipline of sport or physical pursuit calls to your spirit?  |" << std::endl;
    std::cout << "|   * Volleyball                                                       |" << std::endl;
    std::cout << "|   * Athlete (Track / Sprinting / High Endurance)                     |" << std::endl;
    std::cout << "|   * Kho-Kho                                                          |" << std::endl;
    std::cout << "|   * Badminton                                                        |" << std::endl;
    std::cout << "|   * None (Gentle Walks / Quiet Intellectual Life)                    |" << std::endl;
    std::cout << FOREST << "+----------------------------------------------------------------------+" << RESET << std::endl;
    std::cout << BOLD << "> State your pursuit: " << RESET;
    std::cin >> sport;

    printWhisper("A solitary hawk circles the ridge. Your identity draws near...");

    // =========================================================================
    // LEVEL 4: Most Personal (Habits, Ambitions & Soul Signature)
    // =========================================================================
    std::cout << GOLD << "+-- [ INQUIRY IV : THE SIGNATURE OF THE SOUL ] ------------------------+" << RESET << std::endl;

    std::string targetIdentified = "A Wanderer of the Woods";

    // --- CASE A: NO SPECS ---
    if (q_specs == 'n' || q_specs == 'N') {
        // Did their name start with S or J?
        if (q_name_letter == 'n' || q_name_letter == 'N') {
            // ONLY ONE PERSON: VED!
            std::cout << "| Are you an active social media traveler who stays awake as a Night Owl? |" << std::endl;
            std::cout << GOLD << "+----------------------------------------------------------------------+" << RESET << std::endl;
            std::cout << BOLD << "> Your Answer (y/n): " << RESET;
            std::cin >> q_habit;
            targetIdentified = "VED";
        } else {
            // Group: Shlok Moradiya, Shlok Kakadiya, Shrey, Jal
            if (sport == "Athlete" || sport == "athlete" || sport == "athletics" || sport == "a" || sport == "A" || sport == "2") {
                std::cout << "| Do you spend your quiet nights building circuits & target MIT EECS?  |" << std::endl;
                std::cout << GOLD << "+----------------------------------------------------------------------+" << RESET << std::endl;
                std::cout << BOLD << "> Your Answer (y/n): " << RESET;
                std::cin >> q_habit;
                targetIdentified = "SHLOK MORADIYA (Your Highness my LORD!)";
            } else if (sport == "Volleyball" || sport == "volleyball" || sport == "v" || sport == "V" || sport == "1") {
                std::cout << "| Do you walk under the gentle valley sun with social media at hand?   |" << std::endl;
                std::cout << GOLD << "+----------------------------------------------------------------------+" << RESET << std::endl;
                std::cout << BOLD << "> Your Answer (y/n): " << RESET;
                std::cin >> q_habit;
                targetIdentified = "JAL MANGUKIYA";
            } else {
                // Shlok Kakadiya vs Shrey Khokhariya
                std::cout << "| Are you an elite scholar holding top 90%+ marks upon the scrolls?   |" << std::endl;
                std::cout << GOLD << "+----------------------------------------------------------------------+" << RESET << std::endl;
                std::cout << BOLD << "> Your Answer (y/n): " << RESET;
                std::cin >> q_habit;

                if (q_habit == 'y' || q_habit == 'Y') {
                    targetIdentified = "SHLOK KAKADIYA";
                } else {
                    targetIdentified = "SHREY KHOKHARIYA";
                }
            }
        }
    } 
    // --- CASE B: WEARS SPECS ---
    else {
        // Did their name start with S or J?
        if (q_name_letter == 'y' || q_name_letter == 'Y') {
            // ONLY ONE PERSON: SHLOK GOPANI!
            std::cout << "| Do you master the shuttlecock in badminton with swift elegance?      |" << std::endl;
            std::cout << GOLD << "+----------------------------------------------------------------------+" << RESET << std::endl;
            std::cout << BOLD << "> Your Answer (y/n): " << RESET;
            std::cin >> q_habit;
            targetIdentified = "SHLOK GOPANI";
        } else {
            // Group: Moksh, Ansh, Dharma Tarapara, Yagnesh
            if (sport == "Athlete" || sport == "athlete" || sport == "athletics" || sport == "a" || sport == "A" || sport == "2") {
                std::cout << "| Do the teachers of the realm know your name with honour and renown?  |" << std::endl;
                std::cout << GOLD << "+----------------------------------------------------------------------+" << RESET << std::endl;
                std::cout << BOLD << "> Your Answer (y/n): " << RESET;
                std::cin >> q_habit;
                targetIdentified = "YAGNESH";
            } else if (sport == "Volleyball" || sport == "volleyball" || sport == "v" || sport == "V" || sport == "1") {
                std::cout << "| Are you renowned across the school grounds for high academic marks?  |" << std::endl;
                std::cout << GOLD << "+----------------------------------------------------------------------+" << RESET << std::endl;
                std::cout << BOLD << "> Your Answer (y/n): " << RESET;
                std::cin >> q_habit;
                targetIdentified = "DHARMA TARAPARA";
            } else if (sport == "Badminton" || sport == "badminton" || sport == "b" || sport == "B" || sport == "4") {
                std::cout << "| Are you famous in the halls, celebrated both in books and on court?  |" << std::endl;
                std::cout << GOLD << "+----------------------------------------------------------------------+" << RESET << std::endl;
                std::cout << BOLD << "> Your Answer (y/n): " << RESET;
                std::cin >> q_habit;
                targetIdentified = "MOKSH";
            } else {
                std::cout << "| Do you dwell in deep scholarly study, achieving 90%+ on every trial? |" << std::endl;
                std::cout << GOLD << "+----------------------------------------------------------------------+" << RESET << std::endl;
                std::cout << BOLD << "> Your Answer (y/n): " << RESET;
                std::cin >> q_habit;
                targetIdentified = "ANSH";
            }
        }
    }

    // Gentle dramatic pause
    sleepMs(400);
    std::cout << std::endl;
    std::cout << MIST << "    [ The mists part upon the summit... ]" << RESET << std::endl;
    sleepMs(500);

    // =========================================================================
    // CINEMATIC STONE ENGRAVED REVEAL (PURE ASCII)
    // =========================================================================
    std::cout << std::endl;
    std::cout << GOLD << BOLD << "  +======================================================================+" << std::endl;
    std::cout << "  |                      THE ORACLE HAS SPOKEN                           |" << std::endl;
    std::cout << "  |                                                                      |" << std::endl;
    std::cout << "  |   " << SNOW << ">>>  " << GOLD << targetIdentified << SNOW;
    
    // Aesthetic spacing
    int visibleLen = (int)targetIdentified.length();
    int totalSpace = 58 - visibleLen;
    for (int i = 0; i < totalSpace; ++i) std::cout << " ";
    std::cout << GOLD << "|" << std::endl;
    
    std::cout << "  |                                                                      |" << std::endl;
    std::cout << "  |   " << EARTH << DIM << "\"Carved upon the ancient stones of the alpine pass.\"" << RESET << GOLD << BOLD << "               |" << std::endl;
    std::cout << "  +======================================================================+" << RESET << std::endl;
    std::cout << std::endl;

    return 0;
}
