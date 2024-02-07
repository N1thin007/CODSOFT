#include <iostream>

using namespace std;

void initializeBoard(char board[3][3]);
void displayBoard(const char board[3][3]);
bool makeMove(char board[3][3], char player, int row, int col);
bool checkWin(const char board[3][3], char player);
bool checkDraw(const char board[3][3]);
char switchPlayer(char currentPlayer);
bool playAgain();

int main() {
    char board[3][3] = {' '};  
    char currentPlayer = 'X';

    do {
        initializeBoard(board);
        displayBoard(board);

        while (true) {
            int row, col;

            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;

            if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            if (makeMove(board, currentPlayer, row - 1, col - 1)) {
                displayBoard(board);

                if (checkWin(board, currentPlayer)) {
                    cout << "Player " << currentPlayer << " wins!" << endl;
                    break;
                }

                if (checkDraw(board)) {
                    cout << "It's a draw!" << endl;
                    break;
                }

                currentPlayer = switchPlayer(currentPlayer);
            }
        }
    } while (playAgain());

    cout << "Thanks for playing! Goodbye." << endl;

    return 0;
}

void initializeBoard(char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(const char board[3][3]) {
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "  -----" << endl;
        }
    }
    cout << endl;
}

bool makeMove(char board[3][3], char player, int row, int col) {
    if (board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool checkWin(const char board[3][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;  
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
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

bool checkDraw(const char board[3][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;  
            }
        }
    }
    return true;  
}

char switchPlayer(char currentPlayer) {
    return (currentPlayer == 'X') ? 'O' : 'X';
}

bool playAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
