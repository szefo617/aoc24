#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    int a, b;
    int sum1 = 0;
    int sum2 = 0;
    while (getline(cin, s)) {
        auto ss = stringstream(s);
        vector<int> v;
        while (ss >> a) v.push_back(a);
        a = v[0]; b = v[1];
        int dir = a < b;
        int c = abs(a - b);
        if (c == 0 || c > 3) {
            // cout << "zle 1\n";
        } else {
            a = b;
            int j = 2;
            int ok = 1;
            while (j < v.size()) {
                b = v[j]; j++;
                int c = abs(a - b);
                if (a < b != dir || c == 0 || c > 3) ok = 0;
                a = b;
            }
            if (ok)  {
                sum1++;
                sum2++;
                continue;
            }
        }

        for (int i = 0; i < v.size(); i++) {
            vector<int> w;
            for (int j = 0; j < v.size(); j++) if (i != j) w.push_back(v[j]);
            // for (int j = 0; j < w.size(); j++) cout << w[j] << " "; cout << "\n";
            a = w[0]; b = w[1];
            dir = a < b;
            c = abs(a - b);
            if (c == 0 || c > 3) continue;
            a = b;
            int j = 2;
            int ok2 = 1;
            while (j < w.size()) {
                b = w[j]; j++;
                int c = abs(a - b);
                if (a < b != dir || c == 0 || c > 3) ok2 = 0;
                a = b;
            }
            if (ok2) {
                sum2++;
                break;
            }

        }
    }
    cout << sum1 << "\n";
    cout << sum2 << "\n";
    return 0;
}