#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int secretNumber = rand() % 100 + 1;

    int userGuess;
    int attempts = 0;
    bool guessedCorrectly = false;

    cout << "Welcome to the Number Guessing Game!" << endl;
    cout << "Try to guess the secret number between 1 and 100." << endl;

    while (!guessedCorrectly) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        attempts++;

        if (userGuess == secretNumber) {
            guessedCorrectly = true;
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    }

    return 0;
}
