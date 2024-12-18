#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <set>
#define lld long long int
#define ROW 103
#define COL 101

using namespace std;

string s;

set<char> torem = {',', 'v', '=', 'p'};
int cc[4];
vector<int> r, c, dr, dc;
vector<string> rows;

int main() {
    lld sum = 0, sum2 = 0;

    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) if (torem.count(s[i])) s[i] = 32;
        auto ss = stringstream(s);
        int a[4];
        ss >> a[0] >> a[1] >> a[2] >> a[3];
        c.push_back(a[0]); r.push_back(a[1]);
        dc.push_back(a[2]); dr.push_back(a[3]);
    }

    for (int i = 0; i < ROW; i++) {
        rows.push_back("");
        for (int j = 0; j < COL; j++)
            rows[i].push_back('.');
    }
        
    int iter = 0;
    while (true) {
        iter++;
        for (int i = 0; i < r.size(); i++) {
            rows[r[i]][c[i]] = '.';
            c[i] += dc[i]; r[i] += dr[i];
            if (c[i] >= COL) c[i] -= COL;
            if (c[i] < 0) c[i] += COL;
            if (r[i] >= ROW) r[i] -= ROW;
            if (r[i] < 0) r[i] += ROW;
            rows[r[i]][c[i]] = 'X';
        }
        int maxr = 0, curr = 0;
        for (int i = 0; i < rows.size(); i++) {
            for (int j = 0; j < rows[0].size(); j++) {
                if (rows[i][j] == 'X') {
                    curr++;
                    if (curr > maxr) maxr = curr;
                } else {
                    curr = 0;
                }
            }
        }
        if (maxr > 12) {
            cout << iter << "\n";
            for (int i = 0; i < rows.size(); i++) cout << rows[i] << "\n";
        }
    }
    
    cout << sum2 << "\n";
    return 0;
}
