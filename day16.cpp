#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#define lld long long int

using namespace std;

string s;
vector<string> v;

vector<int> dr = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};

struct ent {
    int r;
    int c;
    int d;
    int dist;
    ent(int r, int c, int d, int dist) {
        this->r = r;
        this->c = c;
        this->d = d;
        this->dist = dist;
    }
};
auto cmp = [](const ent &a, const ent &b) { 
    if (a.dist != b.dist) {
        return a.dist < b.dist;
    }
    return (a.r << 10) + (a.c << 2) + a.d < (b.r << 10) + (b.c << 2) + b.d;
};
std::set<ent, decltype(cmp)> ds(cmp);
int vis[150][150][4];

int v2[150][150];

int dfs(int r, int c, int d, int dist) {
    if (vis[r][c][d] != dist) return 0;
    if (v[r][c] == 'E') return 1;
    int ok = 0;
    ok += dfs(r + dr[d], c + dc[d], d, dist + 1);
    ok += dfs(r, c, (d + 1) % 4, dist + 1000);
    ok += dfs(r, c, (d + 3) % 4, dist + 1000);
    if (ok) v2[r][c] = 1;
    return ok;
}

int main() {
    int sum = 0;
    while (getline(cin, s) && s.size()) {
        v.push_back(s);
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[0].size(); j++) {
            for (int k = 0; k < 4; k++) {
                vis[i][j][k] = 999999999;
            }
        }
    }
    ds.insert({(int)v.size() - 2, 1, 0, 0});
    vis[(int)v.size() - 2][1][0] = 0;
    while (!ds.empty()) {
        ent e = *ds.begin();
        ds.erase(ds.begin());
        if (vis[e.r][e.c][e.d] == e.dist) {
            int nr = e.r + dr[e.d];
            int nc = e.c + dc[e.d];
            if (v[nr][nc] != '#') {
                if (e.dist + 1 < vis[nr][nc][e.d]) {
                    vis[nr][nc][e.d] = e.dist + 1;
                    ds.insert({nr, nc, e.d, e.dist + 1});
                }
            }
            int nd = (e.d + 1) % 4;
            if (e.dist + 1000 < vis[e.r][e.c][nd]) {
                vis[e.r][e.c][nd] = e.dist + 1000;
                ds.insert({e.r, e.c, nd, e.dist + 1000});
            }
            nd = (nd + 2) % 4;
            if (e.dist + 1000 < vis[e.r][e.c][nd]) {
                vis[e.r][e.c][nd] = e.dist + 1000;
                ds.insert({e.r, e.c, nd, e.dist + 1000});
            }
        }
    }
    cout << vis[1][v[0].size() - 2][0] << " " << vis[1][v[0].size() - 2][3] << "\n";
    cout << dfs(v.size() - 2, 1, 0, 0) << " ";
    int sum2 = 0;
    for (int i = 0; i < v.size(); i++) for (int j = 0; j < v[0].size(); j++) {
        if (v2[i][j] != 0 || v[i][j] == 'E') sum2++;
    }
    cout << sum2 << "\n";
    return 0;
}
