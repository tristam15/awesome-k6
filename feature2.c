#include <stdio.h>

char board[3][3]; // 3x3 game board

void initialize_board() {
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i;
    printf("-------------\n");
    for (i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

int check_winner() {
    int i;

    // Check rows
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < 3; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 1;
    }

    return 0; // No winner
}

int main() {
    int row, col, player = 1, total_moves = 0;

    initialize_board();

    printf("Tic-Tac-Toe Game\n");
    printf("Player 1: X\nPlayer 2: O\n");
    printf("-------------\n");

    while (1) {
        printf("Player %d, enter your move (row [1-3] and column [1-3]): ", player);
        scanf("%d %d", &row, &col);

        // Convert input to array indices
        row--;
        col--;

        // Check if the move is valid
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            if (player == 1) {
                board[row][col] = 'X';
                player = 2;
            } else {
                board[row][col] = 'O';
                player = 1;
            }
            total_moves++;
            print_board();

            // Check if there is a winner or a tie
            if (check_winner()) {
                printf("Player %d wins!\n", player == 1 ? 2 : 1);
                break;
            } else if (total_moves == 9) {
                printf("It's a tie!\n");
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    return 0;
}
