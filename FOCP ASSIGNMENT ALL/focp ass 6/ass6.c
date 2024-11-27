#include <stdio.h>

#define SIZE 3  // Size of the Tic-Tac-Toe board

// Function to initialize the board with empty spaces
void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to print the board
void printBoard(char board[SIZE][SIZE]) {
    printf("\nTic-Tac-Toe Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
}

// Function to check if a player has won
int checkWinner(char board[SIZE][SIZE], char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return 1; // Win found in row
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return 1; // Win found in column
        }
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return 1; // Win found in the main diagonal
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return 1; // Win found in the anti-diagonal
    }

    return 0; // No win
}

// Function to check if the board is full (draw condition)
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // There's still an empty space
            }
        }
    }
    return 1; // Board is full
}

// Function to handle the player's move
int playerMove(char board[SIZE][SIZE], char player) {
    int row, col;

    // Ask for the player's move
    printf("\nPlayer %c, enter your move (row and column): ", player);
    scanf("%d %d", &row, &col);

    // Check if the position is within the board and the cell is empty
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = player; // Make the move
        return 1; // Valid move
    } else {
        printf("Invalid move. Try again.\n");
        return 0; // Invalid move
    }
}

// Main function to run the game
int main() {
    char board[SIZE][SIZE];
    int gameOver = 0;
    int turn = 0; // 0 for Player 1 (X), 1 for Player 2 (O)
    int moveValid;

    // Initialize the board
    initializeBoard(board);

    printf("Welcome to Tic-Tac-Toe!\n");

    while (!gameOver) {
        printBoard(board); // Display the board

        // Alternate turns between Player 1 (X) and Player 2 (O)
        char currentPlayer = (turn % 2 == 0) ? 'X' : 'O';

        // Handle the player's move
        do {
            moveValid = playerMove(board, currentPlayer);
        } while (!moveValid);

        // Check if the current player has won
        if (checkWinner(board, currentPlayer)) {
            printBoard(board);
            printf("\nPlayer %c wins!\n", currentPlayer);
            gameOver = 1;
        }
        // Check if the board is full (draw)
        else if (isBoardFull(board)) {
            printBoard(board);
            printf("\nIt's a draw!\n");
            gameOver = 1;
        }

        // Switch turns
        turn++;
    }

    return 0;
}
