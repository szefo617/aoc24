#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#define lld long long

using namespace std;

string pat = "mul(0,0)";

int main() {
    string s;
    lld sum1 = 0;
    lld sum2 = 0;
    int d = 1;
    while (getline(cin, s)) {
        s += ".........";
        int m = 0;
        lld a = 0, b = 0;
        for (int i = 0; i < s.size(); i++) {
            auto c = s[i];
            if (s[i] == 'd' && s[i + 1] == 'o') {
                cout << "do " << i << "\n";
                if (s[i + 2] == '(' && s[i + 3] == ')') {
                    d = 1;
                }
                if (s[i + 2] == 'n' && s[i + 3] == '\'' && s[i + 4] == 't' && s[i + 5] == '(' && s[i + 6] == ')') {
                    d = 0;
                }
            }
            if (m == 4) {
                if (c == ',') m++; else
                if (c >= '0' && c <= '9') a = a * 10 + c - 48; else
                { m = a = b = 0; }
            }
            if (m == 6) {
                if (c == ')') m++; else
                if (c >= '0' && c <= '9') b = b * 10 + c - 48; else
                { m = a = b = 0; }
            }
            if (m < 8 && pat[m] != '0') {
                if (c != pat[m]) { m = a = b = 0; }
                if (c == pat[m]) m++;
            }
            if (m == 8) {
                if (a < 1000 && b < 1000)  {
                    sum1 += a * b;
                    sum2 += d * a * b;
                    cout << d << " " << a << " " << b << "\n";
                }
                m = a = b = 0;
            }
        }
    }
    cout << sum1 << "\n";
    cout << sum2 << "\n";
    return 0;
}