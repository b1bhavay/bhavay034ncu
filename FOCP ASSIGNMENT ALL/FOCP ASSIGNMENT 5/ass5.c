#include <stdio.h>
#include <string.h>

#define MAX_TRIES 3  // Number of chances the player has

void displayWord(char word[], char guessedWord[]) {
    // Function to display the current guessed word with blanks
    for (int i = 0; i < strlen(word); i++) {
        if (guessedWord[i] == '_') {
            printf("_ ");
        } else {
            printf("%c ", guessedWord[i]);
        }
    }
    printf("\n");
}

int main() {
    // The word to be guessed
    char word[] = "programming"; 
    int wordLength = strlen(word);
    
    // Array to store the guessed characters (initially all blanks)
    char guessedWord[wordLength];
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }

    char guessedChar;
    int attempts = 0;
    int correctGuesses = 0;

    printf("Welcome to Hangman Game!\n");
    printf("You have %d attempts to guess the word.\n", MAX_TRIES);

    while (attempts < MAX_TRIES) {
        // Display the current guessed word
        displayWord(word, guessedWord);

        // Ask the player to input a guess
        printf("Enter a character to guess: ");
        scanf(" %c", &guessedChar);  // The space before %c to consume any leftover newline character

        int correct = 0;  // Flag to check if the guess is correct

        // Check if the guessed character is in the word
        for (int i = 0; i < wordLength; i++) {
            if (word[i] == guessedChar && guessedWord[i] == '_') {
                guessedWord[i] = guessedChar;
                correct = 1;
                correctGuesses++;
            }
        }

        // If the guess is incorrect, increment the attempts counter
        if (!correct) {
            attempts++;
            printf("Wrong guess! You have %d attempts remaining.\n", MAX_TRIES - attempts);
        }

        // Check if the word is fully guessed
        if (correctGuesses == wordLength) {
            printf("Congratulations! You guessed the word: %s\n", word);
            break;
        }
    }

    if (attempts == MAX_TRIES && correctGuesses != wordLength) {
        printf("Sorry! You've run out of attempts. The word was: %s\n", word);
    }

    return 0;
}
// C program to implement hangman game
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

// Struct to hold a word and its hint
struct WordWithHint {
	char word[MAX_WORD_LENGTH];
	char hint[MAX_WORD_LENGTH];
};

// Function to display the current state of the word
void displayWord(const char word[], const bool guessed[]);

// Function to draw the hangman
void drawHangman(int tries);

// driver code
int main()
{
	// Seed the random number generator with the current
	// time
	srand(time(NULL));
	// Array of words with hints
	struct WordWithHint wordList[] = {
		{ "geeksforgeeks", "Computer coding" },
		{ "elephant", "A large mammal with a trunk" },
		{ "pizza", "A popular Italian dish" },
		{ "beach", "Sandy shore by the sea" },
		// Add more words and hints here
	};

	// Select a random word from the list
	int wordIndex = rand() % 4;

	const char* secretWord = wordList[wordIndex].word;
	const char* hint = wordList[wordIndex].hint;

	int wordLength = strlen(secretWord);
	char guessedWord[MAX_WORD_LENGTH] = { 0 };
	bool guessedLetters[26] = { false };

	printf("Welcome to Hangman!\n");
	printf("Hint: %s\n", hint);

	int tries = 0;

	while (tries < MAX_TRIES) {
		printf("\n");
		displayWord(guessedWord, guessedLetters);
		drawHangman(tries);

		char guess;
		printf("Enter a letter: ");
		scanf(" %c", &guess);
		guess = tolower(guess);

		if (guessedLetters[guess - 'a']) {
			printf("You've already guessed that letter. "
				"Try again.\n");
			continue;
		}

		guessedLetters[guess - 'a'] = true;

		bool found = false;
		for (int i = 0; i < wordLength; i++) {
			if (secretWord[i] == guess) {
				found = true;
				guessedWord[i] = guess;
			}
		}

		if (found) {
			printf("Good guess!\n");
		}
		else {
			printf("Sorry, the letter '%c' is not in the "
				"word.\n",
				guess);
			tries++;
		}

		if (strcmp(secretWord, guessedWord) == 0) {
			printf("\nCongratulations! You've guessed the "
				"word: %s\n",
				secretWord);
			break;
		}
	}

	if (tries >= MAX_TRIES) {
		printf("\nSorry, you've run out of tries. The word "
			"was: %s\n",
			secretWord);
	}

	return 0;
}

void displayWord(const char word[], const bool guessed[])
{
	printf("Word: ");
	for (int i = 0; word[i] != '\0'; i++) {
		if (guessed[word[i] - 'a']) {
			printf("%c ", word[i]);
		}
		else {
			printf("_ ");
		}
	}
	printf("\n");
}

void drawHangman(int tries)
{
	const char* hangmanParts[]
		= { "	 _________", " |		 |",
			" |		 O", " |	 /|\\",
			" |	 / \\", " |" };

	printf("\n");
	for (int i = 0; i <= tries; i++) {
		printf("%s\n", hangmanParts[i]);
	}
}
