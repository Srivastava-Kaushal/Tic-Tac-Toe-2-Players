#include <iostream>
#include <Windows.h>
using namespace std;

const int ROWS = 3;
const int COLS = 3;

char board[ROWS][COLS] = { { '1', '2', '3' }, 
                           { '4', '5', '6' }, 
                           { '7', '8', '9' } };

char player = 'X';

void drawBoard() {
    system("cls");
    cout << "Tic-Tac-Toe" << endl << endl;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << " " << board[i][j] << " ";
            if (j < COLS - 1) {
                cout << "|";
            }
        }
        cout << endl;
        if (i < ROWS - 1) {
            cout << "---+---+---" << endl;
        }
    }
}

void togglePlayer() {
    if (player == 'X') player = 'O';
    else player = 'X';
}

bool checkForWin() {
    // check rows
    for (int i = 0; i < ROWS; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }

    // check cols
    for (int i = 0; i < COLS; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }

    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }

    return false;
}

int main() {
    drawBoard();

    while (true) {
        int move;
        cout << endl << "Player " << player << ", make your move (1-9): ";
        cin >> move;

        int row = (move - 1) / ROWS;
        int col = (move - 1) % COLS;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = player;
        } else {
            cout << "Invalid move. Try again." << endl;
            Sleep(1000);
            continue;
        }

        drawBoard();

        if (checkForWin()) {
            cout << endl << "Player " << player << " wins!" << endl;
            break;
        }

        togglePlayer();
    }

    return 0;
}
