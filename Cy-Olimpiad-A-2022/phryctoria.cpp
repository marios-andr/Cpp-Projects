#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int Rab;// grammes/rows tou AB
    int Cab;// stiles/columns tou AB
    int Rbc;// grammes/rows tou BC
    int Cbc;// stiles/columns tou BC
    int P; //praxeis
    cin >> Rab >> Cab >> Rbc >> Cbc >> P;
    string AB[Rab], BC[Rbc];
    int ABCost[26] = {0}, BCCost[26] = {0}; //65-90
    for (int i = 1; i <= Rab; i++) {
        string a;
        cin >> a;
        AB[i-1] = a;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == '-')
                continue;
            ABCost[a[j] - 65] = i + j + 1;
        }
    }
    for (int i = 1; i <= Rbc; i++) {
        string a;
        cin >> a;
        BC[i-1] = a;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] == '-')
                continue;
            BCCost[a[j] - 65] = i + j + 1;
        }
    }

    for (int i = 0; i < P; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            string M1, M2; // 'A'...'Z' , string.size() <= 20
            cin >> M1 >> M2;
            int flames1 = 0, flames2 = 0;
            for (int j = 0; j < M1.size(); j++)
                flames1 += ABCost[M1[j] - 65] + BCCost[M1[j] - 65];
            for (int j = 0; j < M2.size(); j++)
                flames2 += ABCost[M2[j] - 65] + BCCost[M2[j] - 65];

            if (flames1 > flames2)
                cout << M2 << endl;
            else if (flames1 < flames2 || flames1 == flames2)
                cout << M1 << endl;
        } else if (type == 2) {
            int pinakas; // 1 = AB , 2 = BC
            cin >> pinakas;
            int i1, j1, i2, j2; // 1[i1][j1] = 2[i2][j2]
            cin >> i1 >> j1 >> i2 >> j2;
            if (pinakas == 1) {
                char tmp = AB[i1-1][j1-1];
                char tmp1 = AB[i2-1][j2-1];
                AB[i1-1][j1-1] = tmp1;
                AB[i2-1][j2-1] = tmp;
                if (tmp != '-')
                    ABCost[tmp - 65] = i2 + j2;
                if (tmp1 != '-')
                    ABCost[tmp1 - 65] = i1 + j1;
            } else if (pinakas == 2) {
                char tmp = BC[i1-1][j1-1];
                char tmp1 = BC[i2-1][j2-1];
                BC[i1-1][j1-1] = tmp1;
                BC[i2-1][j2-1] = tmp;
                if (tmp != '-')
                    BCCost[tmp - 65] = i2 + j2;
                if (tmp1 != '-')
                    BCCost[tmp1 - 65] = i1 + j1;
            }
        }
    }
}