#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#define lld long long

using namespace std;

string s;
vector<string> v;
char t[140][140];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int vv[4] = {1, 2, 4, 8};
int r, c, d, sr, sc;

int main() {
    int i = 0;
    while (getline(cin, s)) {
        v.push_back(s);
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '^') { r = sr = i; c = sc = j; }
        }
        i++;
    }
    int sum = 0;
    int sum2 = 0;

    // part1
    while (d != -1) {
        if (!t[r][c]) {
            sum++;
            t[r][c] = 1;
        }
        int nr = r + dr[d], nc = c + dc[d];
        if (nr < 0 || nc < 0 || nr >= v.size() || nc >= v[0].size()) {
            break;
        }
        if (v[nr][nc] == '#') {
            d = (d + 1) % 4;
        } else {
            r = nr;
            c = nc;
        }
    }

    // part2
    for (int x = 0; x < v.size(); x++) for (int y = 0; y < v[0].size(); y++) if (v[x][y] == '.') {
        for (int i = 0; i < v.size(); i++) for (int j = 0; j < v[0].size(); j++) t[i][j] = 0;
        v[x][y] = '#';

        r = sr; c = sc; d = 0;
        while (d != -1) {
            if (t[r][c] & vv[d]) {
                d = -1; break;
            } else {
                t[r][c] |= vv[d];
            }
            
            int nr = r + dr[d], nc = c + dc[d];
            if (nr < 0 || nc < 0 || nr >= v.size() || nc >= v[0].size()) {
                break;
            }
            if (v[nr][nc] == '#') {
                d = (d + 1) % 4;
            } else {
                r = nr;
                c = nc;
            }
        }
        if (d == -1) sum2++;
        v[x][y] = '.';
    }
    cout << sum << "\n";
    cout << sum2 << "\n";
    return 0;
}