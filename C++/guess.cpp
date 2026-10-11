#include <iostream>
#include <string> // Needed to store words/text

int main()
{
    // 1. Store the secret name (Lesson 2: Variables)
    std::string secret_name = "Jarvis";
    std::string user_guess = "";
    int attempts = 0; // Counter (Lesson 3: Math)

    std::cout << "========================================" << std::endl;
    std::cout << " |SECURITY SYSTEM: GUESS THE AI'S NAME|   " << std::endl;
    std::cout << "========================================" << std::endl;

    // 2. Loop until they get it right (Lesson 8: while loop)
    while (user_guess != secret_name)
    {
        std::cout << "\nEnter your guess: ";
        std::cin >> user_guess; // Lesson 5: Interactive Input
        attempts++;

        // 3. Decision Logic (Lesson 6 & 7: if / else)
        if (user_guess == secret_name)
        {
            std::cout << "\n[ACCESS GRANTED] Correct! The AI is " << secret_name << "!" << std::endl;
            std::cout << "Solved in " << attempts << " attempts." << std::endl;
        }
        else
        {
            std::cout << "[ACCESS DENIED] Incorrect name. Try again!" << std::endl;
        }
    }

    return 0;
}