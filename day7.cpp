#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#define lld long long

using namespace std;

string s;

lld concat(lld a, lld b) {
    if (b < 10) return a * 10ll + b;
    if (b < 100) return a * 100ll + b;
    return a * 1000ll + b;
}

int check(lld val, lld cur, vector<int> &v, int d) {
    if (d == v.size()) {
        return cur == val;
    }
    lld cur2 = cur + v[d];
    if (check(val, cur2, v, d + 1)) return 1;
    cur2 = cur * v[d];
    return check(val, cur2, v, d + 1);
}

int check2(lld val, lld cur, vector<int> &v, int d) {
    if (d == v.size()) {
        return cur == val;
    }
    lld cur2 = cur + v[d];
    if (check2(val, cur2, v, d + 1)) return 1;
    cur2 = cur * v[d];
    if (check2(val, cur2, v, d + 1)) return 1;
    cur2 = concat(cur, v[d]);
    return check2(val, cur2, v, d + 1);
}

int main() {

    lld sum = 0, sum2 = 0;
    while (getline(cin, s)) {
        replace(s.begin(), s.end(), ':', ' ');
        stringstream ss(s);
        lld a; ss >> a;
        vector<int> v;
        int b;
        while (ss >> b) {
            v.push_back(b);
        }
        if (check(a, v[0], v, 1)) sum += a;
        if (check2(a, v[0], v, 1)) sum2 += a;
    }

    cout << sum << "\n";
    cout << sum2 << "\n";
    return 0;
}