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
vector<int> v;
vector<int> w;

int main() {
    lld sum = 0;
    lld sum2 = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i] - 48; j++) {
            v.push_back(i % 2 ? -1 : i / 2);
        }
    }
    auto v2 = v;
    int l = 0, r = v.size() - 1;
    while (v[r] == -1) r--;
    while (l != r) {
        if (v[l] == -1) {
            v[l] = v[r];
            r--;
            while (v[r] == -1) r--;
        }
        sum += (lld)l * v[l];
        l++;
    }
    sum += (lld)l * v[l];
    cout << sum << "\n";


    r = v2.size() - 1;
    while (v2[r] == -1) r--;
    while (r > 0) {
        int k = 0; 
        while (v2[r - k] == v2[r]) k++;
        int m = 0;
        for (int l = 0; l < r; l++) {
            if (v2[l] == -1) { 
                m++;
            } else {
                m = 0;
            }
            if (m == k) {
                for (int t = 0; t < k; t++) v2[l - t] = v2[r];
                for (int t = 0; t < k; t++) v2[r - t] = -1;
                break;
            }
        }
        r -= k;
        while (v2[r] == -1) r--;
    }
    for (int i = 0; i < v2.size(); i++) {
        if (v2[i] != -1) {
            sum2 += (lld) i * v2[i];
        }
    }
    cout << sum2 << "\n";
    return 0;
}