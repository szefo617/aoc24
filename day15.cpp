#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#define lld long long int

using namespace std;

string s;
vector<string> v, v2;

map<pair<int,int>, int> tomove;
int dfs(int r, int c, int dr, int dc) {
    if (v2[r][c] == '.') return 1;
    if (v2[r][c] == '#') return 0;
    if (dc) {
        if (dfs(r, c + dc, dr, dc)) {
            v2[r][c + dc] = v2[r][c];
            return 1;
        }
        return 0;
    } else {
        if (v2[r][c] == ']') return dfs(r, c - 1, dr, dc);
        if (tomove.count({r, c}) == 0) {
            tomove[{r, c}] = dfs(r + dr, c, dr, dc) && dfs(r + dr, c + 1, dr, dc);
        }
        return tomove[{r, c}];
    }
    return 1;
}

void dfsmove(int r, int c, int dr) {
    if (v2[r][c] == ']') return dfsmove(r, c - 1, dr);
    if (v2[r][c] == '[') {
        dfsmove(r + dr, c, dr);
        dfsmove(r + dr, c + 1, dr);
        v2[r + dr][c] = '[';
        v2[r + dr][c + 1] = ']';
        v2[r][c] = '.';
        v2[r][c + 1] = '.';
    }    
}

int main() {
    int sum = 0, sum2 = 0;
    int r, c, r2, c2;
    int i = 0;
    
    while (getline(cin, s) && s.size()) {
        v.push_back(s);
        v2.push_back("");
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'O') v2[i] += "[]";
            if (s[j] == '@' || s[j] == '.') v2[i] += "..";
            if (s[j] == '#') v2[i] += "##";
            if (s[j] == '@') {
                r2 = r = i; c = j; c2 = c * 2;
                v[r][c] = '.';
            }
        }
        i++;
    }
    cout << r << " " << c << " " << c2 << "\n";

    while (getline(cin, s)) {
        for (int i = 0; i < s.size(); i++) {
            int dr = 0, dc = 0, nr = r, nc = c;
            if (s[i] == '^') dr = -1;
            if (s[i] == 'v') dr = 1;
            if (s[i] == '<') dc = -1;
            if (s[i] == '>') dc = 1;

            // part1
            nr = r + dr; nc = c + dc;
            while (v[nr][nc] == 'O') {
                nr += dr; nc += dc;
            }
            if (v[nr][nc] == '.') {
                v[nr][nc] = 'O';
                r += dr; c += dc;
                v[r][c] = '.';
            }

            // part2
            nr = r2 + dr; nc = c2 + dc;
            if (dfs(nr, nc, dr, dc)) {
                r2 = nr; c2 = nc;
                if (dr) {
                    dfsmove(r2, c2, dr);
                }
                v2[r2][c2] = '.';
                tomove.clear();
            }

            cout << r2 << " " << c2 << " " << s[i] << "\n";
            v2[r2][c2] = '@';
            for (int j = 0; j < v2.size(); j++) {
                cout << v2[j] << "\n";
            }
            v2[r2][c2] = '.';
        }
    }
    
    for (int i = 0; i < v.size(); i++) for (int j = 0; j < v[0].size(); j++) {
        if (v[i][j] == 'O') sum += i * 100 + j;
    }
    for (int i = 0; i < v2.size(); i++) for (int j = 0; j < v2[0].size(); j++) {
        if (v2[i][j] == '[') sum2 += i * 100 + j;
    }
    cout << sum << "\n";
    cout << sum2 << "\n";
    return 0;
}
