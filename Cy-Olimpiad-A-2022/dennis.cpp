#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N <= 0)
        return 0;

    int sum = 0;
    for (int i = 0; i < N; i++) {
        int chars[26] = { 0 };
        string st;
        cin >> st;
        for (int j = 0; j < st.size(); j++)
            chars[st[j] - 97]++;
        int max = *max_element(chars, chars + 26);
        sum += max;
    }

    if (sum % 4 == 1)
        cout << "07";
    else if (sum % 4 == 2)
        cout << "49";
    else if (sum % 4 == 3)
        cout << "43";
    else if (sum % 4 == 0)
        cout << "01";
}

