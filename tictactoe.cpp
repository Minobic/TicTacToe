#include <iostream>

using namespace std;

class TicTacToe {
    public:
    bool haveWon(char board[3][3], char player) {
        for (int row = 0; row < 3; row++) {        // For rows
            if (board[row][0] == player && board[row][1] == player && board[row][2] == player) {
                return true;
            }
        }

        for (int col = 0; col < 3; col++) {        // For columns
            if (board[0][col] == player && board[1][col] == player && board[2][col] == player) {
                return true;
            }
        }

        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }

        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }
    
        return false;
    }

    void printBoard(char board[3][3]) {
        cout << "+---+---+---+" << endl;
        for (int row = 0; row < 3; row++) {
            cout << "| ";
            for (int col = 0; col < 3; col++) {
                cout << board[row][col] << " | ";
            }
            cout << endl;
            cout << "+---+---+---+" << endl;
        }
    }

    bool isBoardFull(char board[3][3]) {
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row][col] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    char board[3][3];

    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = ' ';
        }
    }

    char player = 'X';
    bool gameOver = false;
    TicTacToe game;

    while (!gameOver) {
        int row = 0, col = 0, input;
        game.printBoard(board);
        cout << "Player " << player << " enter: ";
        cin >> input;

        switch (input) {
            case 1 : row = 0; col = 0; break;
            case 2 : row = 0; col = 1; break;
            case 3 : row = 0; col = 2; break;
            case 4 : row = 1; col = 0; break;
            case 5 : row = 1; col = 1; break;
            case 6 : row = 1; col = 2; break;
            case 7 : row = 2; col = 0; break;
            case 8 : row = 2; col = 1; break;
            case 9 : row = 2; col = 2; break;
        }
    
        if (board[row][col] == ' ') {
            board[row][col] = player;
            gameOver = game.haveWon(board, player);

            if (gameOver) {
                game.printBoard(board);
                cout << "Player " << player << " has won" << endl;
            } else if (game.isBoardFull(board)) {
                gameOver = game.isBoardFull(board);
                if (gameOver) {
                    game.printBoard(board);
                    cout << "It's a tie" << endl;
                }
            } else {
                player = (player == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move. Try again" << endl;
        }
    }

    game.printBoard(board);
    return 0;
}