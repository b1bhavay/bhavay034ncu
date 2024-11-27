#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the choice of the computer
int computerChoice() {
    int choice = rand() % 100; 
    if (choice >= 0 && choice <= 33) {
        return 0; // 0 -> Rock
    } else if (choice >= 34 && choice <= 66) {
        return 1; // 1 -> Paper
    } else {
        return 2; // 2 -> Scissors
    }
}

// Function to print the choice as a string
const char* choiceToString(int choice) {
    if (choice == 0) return "Rock";
    if (choice == 1) return "Paper";
    return "Scissors";
}

// Function to determine the winner of the game
void determineWinner(int user, int computer) {
    if (user == computer) {
        printf("It's a tie!\n");
    } else if ((user == 0 && computer == 2) || 
               (user == 1 && computer == 0) || 
               (user == 2 && computer == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }
}

int main() {
    int userChoice, compChoice;

    // Initialize random number generator
    srand(time(0));

    // Ask user for their choice
    printf("Rock, Paper, Scissors Game\n");
    printf("Enter your choice:\n");
    printf("0 for Rock\n1 for Paper\n2 for Scissors\n");
    printf("Your choice: ");
    scanf("%d", &userChoice);

    // Validate user input
    if (userChoice < 0 || userChoice > 2) {
        printf("Invalid choice! Please choose 0, 1, or 2.\n");
        return 1;  // Exit the program due to invalid input
    }

    // Get the computer's choice
    compChoice = computerChoice();

    // Display the choices
    printf("You chose: %s\n", choiceToString(userChoice));
    printf("Computer chose: %s\n", choiceToString(compChoice));

    // Determine the winner
    determineWinner(userChoice, compChoice);

    return 0;
}
