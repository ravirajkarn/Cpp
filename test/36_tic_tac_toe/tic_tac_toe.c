#include <stdio.h>
#include <stdlib.h> // For system("cls") or system("clear")

char board[3][3]; // The game board
char currentPlayer = 'X'; // Start with player X

// Function to initialize the board
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' '; // Empty spaces
        }
    }
}

// Function to print the board
void printBoard() {
    // Clear screen for better display (works on most systems)
    // On Windows: system("cls");
    // On Linux/macOS: system("clear");
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    printf("\n  1 2 3\n");
    printf(" -------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d|", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf(" -------\n\n");
}

// Function to check if a move is valid
int isValidMove(int row, int col) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) {
        printf("Invalid move! Row and column must be between 1 and 3.\n");
        return 0;
    }
    if (board[row][col] != ' ') {
        printf("Invalid move! That spot is already taken.\n");
        return 0;
    }
    return 1;
}

// Function to make a move
void makeMove(int row, int col) {
    board[row][col] = currentPlayer;
}

// Function to switch player
void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

// Function to check for a win
int checkWin() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == currentPlayer && board[1][j] == currentPlayer && board[2][j] == currentPlayer) {
            return 1;
        }
    }

    // Check diagonals
    if ((board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
        (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)) {
        return 1;
    }

    return 0;
}

// Function to check for a draw
int checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Still empty spaces, not a draw yet
            }
        }
    }
    return 1; // All spaces filled, it's a draw
}

int main() {
    int row, col;
    int gameEnded = 0;

    initializeBoard();

    printf("Welcome to Tic-Tac-Toe!\n");

    while (!gameEnded) {
        printBoard();
        printf("Player %c, enter your move (row column): ", currentPlayer);
        // Using `scanf` to read input
        if (scanf("%d %d", &row, &col) != 2) {
            printf("Invalid input. Please enter two numbers (row and column).\n");
            // Clear invalid input from buffer
            while (getchar() != '\n');
            continue;
        }

        // Adjust for 0-based indexing
        row--;
        col--;

        if (isValidMove(row, col)) {
            makeMove(row, col);

            if (checkWin()) {
                printBoard();
                printf("Player %c wins! Congratulations!\n", currentPlayer);
                gameEnded = 1;
            } else if (checkDraw()) {
                printBoard();
                printf("It's a draw!\n");
                gameEnded = 1;
            } else {
                switchPlayer();
            }
        }
    }

    printf("Game Over.\n");
    return 0;
}