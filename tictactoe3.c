#include <stdio.h>

char board[3][3]; // The Tic Tac Toe board
char playerNames[2][50]; // To store player names

// this function initializes the board with board 
void initializeBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int checkWin() {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return 1;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return 1;
        }
    }
    
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return 1;
    }
    
    // Check for a draw
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Game still ongoing
            }
        }
    }
    
    return -1; // Draw
}

int main() {
    printf("Enter Player 1's name: ");
    scanf("%s", playerNames[0]);
    
    printf("Enter Player 2's name: ");
    scanf("%s", playerNames[1]);
    
    int player = 1; // Player 1 starts
    int row, col, input;
    int playerScores[2] = {0}; // Initialize player scores
    
    printf("\n=== Tic Tac Toe - Best of 5 ===\n\n");

    while (playerScores[0] < 3 && playerScores[1] < 3) { // Continue until a player wins 3 games
        printf("\n--- Game %d ---\n\n", playerScores[0] + playerScores[1] + 1);
        
        initializeBoard();
        
        while (1) {
            printBoard();
            printf("%s, enter a number (1-9): ", playerNames[player - 1]);
            scanf("%d", &input);
            
            row = (input - 1) / 3;
            col = (input - 1) % 3;
            
            if (input < 1 || input > 9 || board[row][col] != ' ') {
                printf("Invalid input. Try again.\n");
                continue;
            }
            
            board[row][col] = (player == 1) ? 'X' : 'O';
            
            int result = checkWin();
            if (result == 1) {
                printBoard();
                printf("%s wins!\n", playerNames[player - 1]);
                playerScores[player - 1]++;
                break;
            } else if (result == -1) {
                printBoard();
                printf("It's a draw!\n");
                break;
            }
            
            player = (player == 1) ? 2 : 1;
        }
        
        printf("\n%s: %d | %s: %d\n", playerNames[0], playerScores[0], playerNames[1], playerScores[1]);
        
        player = 1; // Reset player for the next game
    }

    if (playerScores[0] == 3) {
        printf("\n%s wins the series!\n", playerNames[0]);
    } else {
        printf("\n%s wins the series!\n", playerNames[1]);
    }
    
    return 0;
}
