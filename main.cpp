#include <iostream>
#include "welcome.h"

int main() {
    // ASCII Art and welcome message
    welcome();

    // Seed the random number generator with the current time
    // This ensures that each time the program runs, the random numbers will be different
    // without this line, rand() will generate the same sequence of "random" numbers every time
    srand(time(0));  // time(0) returns the current time in seconds, providing a changing value for the seed

    // Generate and display a random number between 0 and 100
    int randomNumber = rand() % 101;  // rand() % 101 generates a number from 0 to 100

    // User's guess
    int userGuess;

    // Guess counter
    int guessCounter = 0;

    // Game is on 
    bool gamePlay = true;

    std::cout << "\nI have picked a number between 1 and 100. Can you guess it?\n";
    std::cout << "Try to find the number with as few guesses as possible!\n\n";

    do {
        guessCounter++;

        std::cout << "\nEnter your guess: ";
        std::cin >> userGuess;

        if (std::cin.fail()) {
            std::cin.clear();  // Clear the error flag
            std::cin.ignore(INT_MAX, '\n');  // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 100.\n";
            continue;
        }

        if (userGuess > randomNumber) {
            std::cout << "Your guess is too high. Try a lower number!\n";
        }
        else if (userGuess < randomNumber) {
            std::cout << "Your guess is too low. Try a higher number!\n";
        }
        else if (userGuess == randomNumber) {
            std::cout << "Congratulations! You found the number: " << randomNumber << ", on: " << guessCounter << " attempt." << "\n";
            gamePlay = false;
        }
    } while (gamePlay);

    std::cout << "Thank you for playing! Goodbye!\n";

    return 0;
}
