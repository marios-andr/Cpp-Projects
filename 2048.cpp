#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int spaceAmount = 0;

int randPos();

void drawBoard(int A[4][4], int score);

void fillRand(int A[4][4]);

bool isFull(int A[4][4]);

bool move(int A[4][4], char move, int &score);

int main() {
    srand(time(NULL));
    int score = 0;
    int A[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            A[i][j] = 0;
        }
    }
    fillRand(A);
    fillRand(A);

    cout << "Enter w, a, s, d to move the numbers\n";

    drawBoard(A, score);

    while (!isFull(A)) {
        char movee;
        cin >> movee;
        if (move(A, movee, score)) {
            fillRand(A);
            drawBoard(A, score);
        }
    }

    return 0;
}

int randPos() {
    return rand() % 4;
}

void drawBoard(int A[4][4], int score) {
    cout << "Score: " << score << "\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (A[i][j] == 0)
                cout << " ";
            else
                cout << A[i][j];

            int a = spaceAmount - (A[i][j] == 0 ? 0 : (int) log10((double) A[i][j]));
            if (a > 0)
                for (int k = 0; k < a; k++)
                    cout << " ";

            cout << (j == 3 ? "\n" : " | "); // mini if. pemou kati gia touto tzai na sou fakiso poupano
        }
        for (int j = 0; j < 14 + (spaceAmount) * 2; j++) {
            cout << "-";
        }
        cout << "\n";
    }
}

void fillRand(int A[4][4]) {
    bool filled = false;
    while (!filled) {
        int a = randPos(), b = randPos();
        if (A[a][b] == 0) {
            if (rand() % 100 <= 9) // 10% chance gia 4
                A[a][b] = 4;
            else
                A[a][b] = 2;
            filled = true;
        }
    }
}

bool isFull(int A[4][4]) {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (A[i][j] == 0)
                return false;
    return true;
}

bool move(int A[4][4], char move, int &score) {
    int di, dj;
    switch (move) {
        case 'w':
            di = -1;
            dj = 0;
            break;
        case 'a':
            di = 0;
            dj = -1;
            break;
        case 's':
            di = 1;
            dj = 0;
            break;
        case 'd':
            di = 0;
            dj = 1;
            break;
        default:
            cout << "Wrong key dumbass\n";
            return false;
    }

    bool hasMoved = false;

    for (int k = 0; k < 1; k++) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Di = i + di, Dj = j + dj;
                bool stop = false;
                while (!stop) {
                    stop = true;
                    if (A[Di - di][Dj - dj] != 0 && Di < 4 && Di > -1 && Dj < 4 && Dj > -1) {
                        int next = A[Di][Dj];
                        if (next == 0) {
                            A[Di][Dj] = A[Di - di][Dj - dj];
                            A[Di - di][Dj - dj] = 0;
                            Di += di;
                            Dj += dj;
                            stop = false;
                            hasMoved = true;
                            k = -1;
                        } else if (next == A[Di - di][Dj - dj]) {
                            A[Di][Dj] *= 2;
                            A[Di - di][Dj - dj] = 0;
                            score += A[Di][Dj];
                            spaceAmount = max((int) log10((double) A[Di][Dj]), spaceAmount);
                            hasMoved = true;
                            k = -1;
                        }
                    }
                }
            }
        }
    }
    return hasMoved;
}
