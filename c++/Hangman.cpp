#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

vector<string> words = {"programming", "hangman", "algorithm", "computer", "game", "challenge"};
const int maxAttempts = 6;

string getRandomWord() {
    srand(time(0));
    int randomIndex = rand() % words.size();
    return words[randomIndex];
}

int main() {
    string wordToGuess = getRandomWord();
    int wordLength = wordToGuess.length();
    string guessedWord(wordLength, '_');
    int attempts = 0;

    cout << "Welcome to Hangman!" << endl;

    while (attempts < maxAttempts && guessedWord != wordToGuess) {
        cout << "Word to guess: " << guessedWord << endl;
        cout << "Attempts remaining: " << maxAttempts - attempts << endl;
        
        char guess;
        cout << "Enter a letter: ";
        cin >> guess;
        
        bool correctGuess = false;
        
        for (int i = 0; i < wordLength; i++) {
            if (wordToGuess[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }
        
        if (!correctGuess) {
            cout << "Incorrect guess. Try again." << endl;
            attempts++;
        }
    }

    if (guessedWord == wordToGuess) {
        cout << "Congratulations! You've guessed the word: " << wordToGuess << endl;
    } else {
        cout << "Out of attempts. The word was: " << wordToGuess << endl;
    }

    return 0;
}
