#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#define lld long long

using namespace std;

string s;
vector<string> v;
char vis[60][60];
vector<int> dr = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};

int dfs(int r, int c) {
    if (vis[r][c]) return 0;
    // vis[r][c] = 1;
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < v.size() && nc >= 0 && nc < v[0].size()) {
            if (v[nr][nc] == v[r][c] + 1)
                res += dfs(nr, nc);
        }
    }
    if (v[r][c] == '9') res++;
    return res;
}

int main() {
    int sum = 0;
    while (cin >> s) {
        v.push_back(s);
    }
    for (int i = 0; i < v.size(); i++) for (int j = 0; j < v[0].size(); j++) if (v[i][j] == '0') {
        for (int k = 0; k < v.size(); k++) for (int l = 0; l < v[0].size(); l++) vis[k][l] = 0;
        sum += dfs(i, j);
    }
    cout << sum << "\n";
    return 0;
}