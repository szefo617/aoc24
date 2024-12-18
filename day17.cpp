#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#define lld long long int

using namespace std;

string s, s2;

lld a, b, c;
vector<int> v;
int t;

lld combo(int op, lld a, lld b, lld c) {
    if (op < 4) return op;
    if (op == 4) return a;
    if (op == 5) return b;
    if (op == 6) return c;
    cout << "DUPA";
    return 0;
}

void comp(lld a, vector<int> &res) {
    lld b = 0, c = 0;
    int p = 0;
    while (p < v.size()) {
        switch(v[p]) {
            case 0: {
                a = a >> combo(v[p + 1], a, b, c);
            } break;
            case 1: {
                b = b ^ v[p + 1];
            } break;
            case 2: {
                b = combo(v[p + 1], a, b, c) % 8;
            } break;
            case 3: {
                if (a) {
                    p = v[p + 1] - 2;
                }
            } break;
            case 4: {
                b = b ^ c;
            } break;
            case 5: {
                res.push_back(combo(v[p + 1], a, b, c) % 8);
            } break;
            case 6: {
                b = a >> combo(v[p + 1], a, b, c);
            } break;
            case 7: {
                c = a >> combo(v[p + 1], a, b, c);
            } break;
        }
        p += 2;
    }
}

lld dfs(lld iter, int d) {
    if (d == -1) return iter;
    lld inc = 1ll << (d * 3);
    vector<int> res;
    for (int i = 0; i < 8; i++) {
        comp(iter, res);
        for (int j = 0; j < res.size() - 1; j++) cout << res[j] << ",";
        cout << res[res.size() - 1] << "\n";
        if (res[d] == v[d]) {
            lld ds = dfs(iter, d - 1);
            if (ds) return ds;
        }
        res.clear();
        iter += inc;
    }
    return 0;
}

int main() {
    int sum = 0;
    cin >> s >> s2 >> a;
    cin >> s >> s2 >> b;
    cin >> s >> s2 >> c;
    getline(cin, s);
    getline(cin, s);
    getline(cin, s);
    replace(s.begin(), s.end(), ',', ' ');
    stringstream ss(s);
    ss >> s2;
    while (ss >> t) {
        v.push_back(t);
    }
    
    cout << dfs(1ll << 45, 15) << "\n";
    return 0;
}
