#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    int N, M, K; //nomizmata, filoi, sinallages
    cin >> N >> M >> K;
    double X[N];// conversions
    for (int i = 0; i < N; i++)
        cin >> X[i];

    long A[M], sum = 0, max = 0, maxi;
    for (int i = 0; i < M; i++)
        A[i] = 0;

    for (int i = 0; i < K; i++) {
        int Fi, Ci;
        double Ai;
        cin >> Fi >> Ai >> Ci;
        int total = (int) round(Ai * X[Ci - 1] * 100);
        A[Fi - 1] += total;
        sum += total;
        if (A[Fi - 1] > max) {
            max = A[Fi - 1];
            maxi = Fi - 1;
        }
    }

    cout << M - 1 << endl;
    int avg = sum / M;
    int remainder = sum % M;
    for (int i = 0; i < M; i++) {
        if (i == maxi)
            continue;

        int pay = avg - A[i];
        if (remainder > 0) {
            pay++;
            remainder--;
        }

        cout << i + 1 << " " << maxi + 1 << " " << fixed << setprecision(2) << pay / 100.0 << endl;
    }

    return 0;
}