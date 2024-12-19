#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <set>
#define lld long long int
#define MAXC 6

using namespace std;

vector<int> dr = {0, 1, 0, -1};
vector<int> dc = {1, 0, -1, 0};

string s;
int v[MAXC + 1][MAXC + 1];
int w[MAXC + 1][MAXC + 1];

struct tri {
    int r;
    int c;
    int dist;
    tri(int r, int c, int dist) {
        this->r = r;
        this->c = c;
        this->dist = dist;
    }
};

int a, b;
int main() {
    while (getline(cin,s)) {
        replace(s.begin(), s.end(), ',', ' ');
        stringstream ss(s);
        ss >> a >> b;
        v[a][b] = '#';
        
        for (int i = 0; i <= MAXC; i++) for (int j = 0; j <= MAXC; j++) {
            w[i][j] = 999999999;
        }
        queue<tri> q;
        q.push({0, 0, 0});
        while (!q.empty()) {
            auto e = q.front();
            q.pop();
            if (e.dist < w[e.r][e.c]) {
                w[e.r][e.c] = e.dist;
                for (int i = 0; i < 4; i++) {
                    int nr = e.r + dr[i];
                    int nc = e.c + dc[i];
                    if (nr >= 0 && nr <= MAXC && nc >= 0 && nc <= MAXC && v[nr][nc] == 0) {
                        q.push({nr, nc, e.dist + 1});
                    }
                }
            }
        }
        if (w[MAXC][MAXC] == 999999999) {
            cout << a << "," << b << "\n";
            break;
        }
    }
    return 0;
}
