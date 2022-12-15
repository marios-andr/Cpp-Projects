#include <iostream>
#include <string>
#include <array>

using namespace std;

bool isCompleted(int pos[3][3]) {
    int filled = 0;
    for (int i = 0; i < 3; i++) {
        int winner;
        bool isWin = false;
        for (int j = 0; j < 3; j++) {
            int yes = pos[i][j];
            if (yes == 0 || yes == 1) {
                filled++;

                if (j == 0) {
                    isWin = pos[i][j + 1] == yes && pos[i][j + 2] == yes;
                    winner = yes;
                }
                if (!isWin && i == 0) {
                    isWin = pos[i + 1][j] == yes && pos[i + 2][j] == yes;
                    winner = yes;
                }
                if (!isWin && i == 0 && j == 0) {
                    isWin = pos[i + 1][j + 1] == yes && pos[i + 2][j + 2] == yes;
                }
            } else {
                isWin = false;
            }
        }
        if (isWin) {
            cout << "Player " << (winner == 0 ? 'X' : 'O') << " has won the game!";
            return true;
        }
    }

    return filled >= 9;
}

int getCompletingPos(int xo, int p1, int p2) {
    return (p1 == xo && p2 == 3) ? 2 : (p1 == 3 && p2 == xo) ? 1 : 0;
}

bool assessPos(int xo, int pos[3][3]) {
    int yay;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int yes = pos[i][j];
            if (yes == xo) {
                if (j == 0) {
                    yay = getCompletingPos(xo, pos[i][j + 1], pos[i][j + 2]);
                    if (yay == 1 || yay == 2) {
                        pos[i][j + yay] = 0;
                        return true;
                    }
                }
                if (i == 0) {
                    yay = getCompletingPos(xo, pos[i + 1][j], pos[i + 2][j]);
                    if (yay == 1 || yay == 2) {
                        pos[i + yay][j] = 0;
                        return true;
                    }
                }
                if (i == 0 && j == 0) {
                    yay = getCompletingPos(xo, pos[i + 1][j + 1], pos[i + 2][j + 2]);
                    if (yay == 1 || yay == 2) {
                        pos[i + yay][j + yay] = 0;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

void drawBoard(int pos[3][3]) {
    string board;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (pos[i][j] == 0)
                board += "X";
            else if (pos[i][j] == 1)
                board += "O";
            else
                board += " ";

            if (j < 2)
                board += "|";
        }
        board += "\n";
        if (i < 2)
            board += "-----\n";
    }

    cout << board;
}

int main() {
    bool isTwoPlayer = false;
    int entered, totalMoves = 0;
    char turn = 'X';
    int pos[3][3] = {
            {3, 3, 3},
            {3, 3, 3},
            {3, 3, 3}
    };

    //cout << "Would you like to play against another player?\n";
    //cin >> isTwoPlayer;
    // c++ lio xanti kai den mporo na kamo cin gia booleans

    while (!isCompleted(pos)) {
        if (isTwoPlayer) {
            drawBoard(pos);
            cout << "Player " << turn << ": Enter position from 0-8 to move to\n";
            cin >> entered;
            if (!(entered >= 0 && entered <= 8)) {
                cout << "Invalid position";
                continue;
            }

            pos[entered / 3][entered % 3] = turn == 'X' ? 0 : 1;
        } else {
            if (turn == 'O') {
                cout << "Player " << turn << ": Enter position from 0-8 to move to\n";
                cin >> entered;
                if (!(entered >= 0 && entered <= 8) || pos[entered / 3][entered % 3] != 3) {
                    cout << "Invalid position\n";
                    continue;
                }

                pos[entered / 3][entered % 3] = 1;
            } else {
                if (assessPos(0, pos) || assessPos(1, pos)) {
                } else if (totalMoves == 0) {
                    pos[0][0] = 0;
                } else if (totalMoves == 2) {
                    if (pos[0][2] == 3 && pos[0][1] == 3)
                        pos[0][2] = 0;
                    else if (pos[1][0] == 3 && pos[2][0] == 3)
                        pos[2][0] = 0;
                } else if (totalMoves == 4) {
                    if (pos[2][2] == 3)
                        pos[2][2] = 0;
                    else if (pos[2][0] == 3)
                        pos[2][0] = 0;
                }

                cout << "________________________________________________\n";
                cout << "Player X has played: \n";
            }
        }

        turn = turn == 'X' ? 'O' : 'X';
        totalMoves++;
        drawBoard(pos);
    }

    return 0;
}
