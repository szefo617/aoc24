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
vector<pair<int, int>> v[128]; // 48 - 122
char res[60][60];
char res2[60][60];

int main() {
    int sum = 0;
    int sum2 = 0;
    int i = 0, j = 0;
    while (getline(cin, s)) {
        for (j = 0; j < s.size(); j++) {
            v[s[j]].push_back({i, j});
        }
        i++;
    }
    for (int k = 48; k <= 122; k++) {
        for (int l = 0; l < v[k].size(); l++) for (int m = l + 1; m < v[k].size(); m++) {
            vector<int> i1 = {2 * v[k][l].first  - v[k][m].first,  2 * v[k][m].first  - v[k][l].first};
            vector<int> j1 = {2 * v[k][l].second - v[k][m].second, 2 * v[k][m].second - v[k][l].second};
            for (int n : {0, 1}) {
                if (i1[n] >= 0 && i1[n] < i && j1[n] >= 0 && j1[n] < j) {
                    if (!res[i1[n]][j1[n]]) {
                        res[i1[n]][j1[n]] = 1;
                        sum++;
                    }
                }
            }

            int g = gcd(abs(v[k][l].first  - v[k][m].first), abs(v[k][l].second - v[k][m].second));
            // cout << g << abs(v[k][l].first  - v[k][m].first) << " " << abs(v[k][l].second - v[k][m].second) << " " << k << "\n";
            i1 = {(v[k][l].first  - v[k][m].first) / g};  i1.push_back(-i1[0]);
            j1 = {(v[k][l].second - v[k][m].second) / g}; j1.push_back(-j1[0]);
            for (int n : {0, 1}) {
                int i2 = v[k][l].first;
                int j2 = v[k][l].second;
                while (i2 >= 0 && i2 < i && j2 >= 0 && j2 < j) {
                    if (!res2[i2][j2]) {
                        // cout << " " << i2 << " " << j2 << "\n";
                        res2[i2][j2] = 1;
                        sum2++;
                    }
                    i2 += i1[n];
                    j2 += j1[n];
                }
            }

        }
    }
    cout << sum << "\n";
    cout << sum2 << "\n";
    return 0;
}