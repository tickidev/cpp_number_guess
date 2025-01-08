#include <iostream>
#include "welcome.h"

int main() {
	// ASCII Art
	welcome();
	
	// Seed the random number generator with the current time
	// This ensures that each time the program runs, the random numbers will be different
	// without this line, rand() will generate the same sequence of "random" numbers every time
	srand(time(0));  // time(0) returns the current time in seconds, providing a changing value for the seed

	// Generates a number between 0 and 100
	int computerNumber = rand() % 101; // rand() % 101 generates a number from 0 to 100
	
	int userGuess;

	bool gamePlay = true;

	std::cout << "\n\nNow I create a number between 1 - 100, try to guess!\n";


	do {
		std::cout << "\nWhat is your guess: ";
		std::cin >> userGuess;

		if (userGuess > computerNumber) {
			std::cout << "Your guess is too high. Try a lower number!\n";
		} 
		else if (userGuess < computerNumber) {
			std::cout << "Your guess is too low. Try a higher number!\n";
		}
		else if (userGuess == computerNumber) {
			std::cout << "Congratulations! You found the correct number! " << computerNumber << "\n";
			gamePlay = false;
		}
		else {
			std::cout << "\nInvalid input. Please enter a number between 1 and 100.\n";
			break;
		}
	} while (gamePlay);

	std::cout << "Thank you for playing! Goodbye!\n";
	return 0;

}