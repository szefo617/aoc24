#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#define lld long long

using namespace std;

string s;
map <pair<int,int>, bool> m;

int main() {
    while (getline(cin, s) && s.size()) {
        replace(s.begin(), s.end(), '|', ' ');
        stringstream ss(s);
        int a, b;
        ss >> a >> b;
        m[{a, b}] = true;
    }
    int sum = 0, sum2 = 0;
    while (getline(cin, s)) {
        replace(s.begin(), s.end(), ',', ' ');
        stringstream ss(s);
        int a;
        vector<int> v;
        ss >> a;
        v.push_back(a);
        int good = 1;
        while (ss >> a) {
            v.push_back(a);
            for (int i = 0; i < v.size(); i++) {
                for (int j = i + 1; j < v.size(); j++) {
                    if (m[{v[j], v[i]}]) {
                        swap(v[i], v[j]);
                        good = 0;
                        i = -1;
                        break;
                    }
                }
            }
        }
        int b = v[v.size() / 2];
        if (good) {
            sum += b;
        } else {
            sum2 += b;
        }
    }
    cout << sum << "\n";
    cout << sum2 << "\n";

    return 0;
}