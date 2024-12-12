#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#define lld long long
#define MAXN 150

using namespace std;
vector <string> v;
string pat = "XMAS";
vector<int> dx = {1, 1,  1,  0, -1, -1, -1, 0};
vector<int> dy = {1, 0, -1, -1, -1,  0,  1, 1};

int main() {
    string s, s2; 
    s2.resize(MAXN, '.');
    v.push_back(s2);
    while (getline(cin, s)) {
        v.push_back("." + s + ".");
    }
    v.push_back(s2);
    int sum = 0;
    int sum2 = 0;
    for (int i = 1; i < v.size() - 1; i++) {
        for (int j = 1; j < v[1].size() - 1; j++) {
            for (int k = 0; k < 8; k++) {
                int l = 0;
                int i1 = i, j1 = j;
                while (l < 4) {
                    if (v[i1][j1] == pat[l]) {
                        l++;
                        i1 += dx[k];
                        j1 += dy[k];
                    } else {
                        break;
                    }
                }
                if (l == 4) {
                    sum++;
                }
            }
            if (v[i][j] == 'A') {
                if ((v[i + 1][j + 1] == 'M' && v[i - 1][j - 1] == 'S') || 
                    (v[i + 1][j + 1] == 'S' && v[i - 1][j - 1] == 'M')) {
                    if ((v[i - 1][j + 1] == 'M' && v[i + 1][j - 1] == 'S') || 
                        (v[i - 1][j + 1] == 'S' && v[i + 1][j - 1] == 'M')) {
                        sum2++;
                    }
                }
            }
        }
    }
    cout << sum << "\n";
    cout << sum2 << "\n";
    return 0;
}