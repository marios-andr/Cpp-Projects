#include <iostream>
#include <cmath>

using namespace std;

string toRoman(int num) {
    string r = "";
    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    for (int i = 0; i < 13; ++i)
    {
        while(num - values[i] >= 0)
        {
            r += str_romans[i];
            num -= values[i];
        }
    }

    return r;
}

int main() {
    string st;
    cin >> st;

    int num = 0;
    string nums = "", newSt;
    for (int i = st.size() - 1; i >= -1; i--) {
        if (i == -1 || (st[i] >= 65 && st[i] <= 90)) {
            if (!nums.empty()) {
                st.erase(i+1, nums.size());
                st.insert(i+1, toRoman(num));
                i = st.size();
                num = 0;
                nums = "";
            }
            continue;
        }
        nums += st[i];
        switch (st[i]) {
            case '0':
                break;
            case '1': {
                double a = pow(10.0, nums.length()-1.0);
                num = num + 1 * a;
                break;
            }
            case '2': {
                double a = pow(10.0, nums.length()-1.0);
                num = num + 2 * a;
                break;
            }
            case '3': {
                double a = pow(10.0, nums.length()-1.0);
                num = num + 3 * a;
                break;
            }
            case '4': {
                double a = pow(10.0, nums.length()-1.0);
                num = num + 4 * a;
                break;
            }
            case '5': {
                double a = pow(10.0, nums.length()-1.0);
                num = num + 5 * a;
                break;
            }
            case '6': {
                double a = pow(10.0, nums.length()-1.0);
                num = num + 6 * a;
                break;
            }
            case '7': {
                double a = pow(10.0, nums.length()-1.0);
                num = num + 7 * a;
                break;
            }
            case '8': {
                double a = pow(10.0, nums.length()-1.0);
                num = num + 8 * a;
                break;
            }
            case '9': {
                double a = pow(10.0, nums.length()-1.0);
                num = num + 9 * a;
                break;
            }
        }
    }
    cout << st;

    return 0;
}