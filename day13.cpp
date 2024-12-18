#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>
#define lld long long int
#define ADD_ME 10000000000000ll

using namespace std;

string s;
lld b[2][2];
lld p[2];

set<char> torem = {',', 'Y', '=', '+'};

int main() {
    lld sum = 0, sum2 = 0;

    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) if (torem.count(s[i])) s[i] = 32;
        auto ss = stringstream(s.substr(12));
        ss >> b[0][0] >> b[0][1];
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) if (torem.count(s[i])) s[i] = 32;
        ss = stringstream(s.substr(12));
        ss >> b[1][0] >> b[1][1];
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) if (torem.count(s[i])) s[i] = 32;
        ss = stringstream(s.substr(9));
        ss >> p[0] >> p[1];
        getline(cin, s);

        lld d, a0, b0;
        d = b[0][0] * b[1][1] - b[0][1] * b[1][0];
        a0 = p[0] * b[1][1] - p[1] * b[1][0];
        b0 = p[1] * b[0][0] - p[0] * b[0][1];
        if (a0 % d == 0 && b0 % d == 0 && a0 / d >= 0 && b0 / d >= 0) {
            a0 = a0 / d; 
            b0 = b0 / d;
            sum += a0 * 3 + b0;
        }

        p[0] += ADD_ME; p[1] += ADD_ME;
        d = b[0][0] * b[1][1] - b[0][1] * b[1][0];
        a0 = p[0] * b[1][1] - p[1] * b[1][0];
        b0 = p[1] * b[0][0] - p[0] * b[0][1];
        if (a0 % d == 0 && b0 % d == 0 && a0 / d >= 0 && b0 / d >= 0) {
            a0 = a0 / d; 
            b0 = b0 / d;
            sum2 += a0 * 3 + b0;
        }

    }
    cout << sum << "\n";
    cout << sum2 << "\n";
    return 0;
}
