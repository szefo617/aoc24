#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#define lld long long
#define MAXN 150

using namespace std;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<string> v;
char w[MAXN][MAXN];

vector<pair<int, int>> sd[4];

// [area, perimeter]
pair<int, int> dfs(int r, int c, char st, int d) {
    if (v[r][c] != st) {
        sd[d].push_back({r, c});
        return {0, 1};
    }
    if (w[r][c]) return {0, 0};
    w[r][c] = 1;
    pair<int, int> res = {1, 0};
    for (int i = 0; i < 4; i++) {
        auto t = dfs(r + dr[i], c + dc[i], st, i);
        res = {res.first + t.first, res.second + t.second};
    }
    return res;
}

main() {
    string s, s2; 
    s2.resize(MAXN, '.');
    v.push_back(s2);
    while (getline(cin, s)) {
        v.push_back("." + s + ".");
    }
    v.push_back(s2);

    int sum = 0;
    int sum2 = 0;
    for (int i = 1; i < v.size() - 1; i++) for (int j = 1; j < v[1].size() - 1; j++) {
        for (int k = 0; k < 4; k++) sd[k].clear();
        auto res = dfs(i, j, v[i][j], 0);
        if (res.first) {
            sum += res.first * res.second;

            int sides = 0;
            for (int k = 0; k < 4; k++) {
                if (k % 2 == 0) {
                    sort(sd[k].begin(), sd[k].end(), 
                        [](const auto &a, const auto &b) {
                            if (a.first != b.first) {
                                return a.first < b.first; 
                            }
                            return a.second < b.second;
                        });
                    pair<int, int> a = {-1, -1};
                    for (int l = 0; l < sd[k].size(); l++) {
                        if (sd[k][l].first != a.first || sd[k][l].second > a.second + 1) sides++;
                        a = sd[k][l];
                    }
                } else {
                    sort(sd[k].begin(), sd[k].end(), 
                        [](const auto &a, const auto &b) {
                            if (a.second != b.second) {
                                return a.second < b.second; 
                            }
                            return a.first < b.first;
                        });
                    pair<int, int> a = {-1, -1};
                    for (int l = 0; l < sd[k].size(); l++) {
                        if (sd[k][l].second != a.second || sd[k][l].first > a.first + 1) sides++;
                        a = sd[k][l];
                    }
                }
                
            }
            sum2 += res.first * sides;
        }
    }
    cout << sum << "\n";
    cout << sum2 << "\n";
    return 0;
}