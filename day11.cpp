#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#define lld long long

using namespace std;

vector<int> v;
map<pair<lld, int>, lld> um;
vector<lld> ds = {1};

int len(lld a) {
    auto r = upper_bound(ds.begin(), ds.end(), a) - ds.begin();
    return r;
}

lld dfs(lld a, int d) {
    if (d == 0) return 1;
    if (a == 0) return dfs(1, d - 1);
    int l = len(a);
    if (um[{a, d}]) return um[{a, d}];
    if (l % 2) {
        um[{a, d}] = dfs(a * 2024, d - 1);
    } else {
        int a1 = a / ds[l / 2], a2 = a % ds[l / 2];
        um[{a, d}] = dfs(a1, d - 1) + dfs(a2, d - 1);
    }
    return um[{a, d}];
}

main() {
    for (int i = 0; i < 17; i++) ds.push_back(ds.back() * 10);
    int a;
    while (cin >> a) v.push_back(a);
    
    lld sum = 0;
    for (int i = 0; i < v.size(); i++) {
        lld a = dfs(v[i], 25);
        cout << v[i] << " " << a << "\n";
        sum += a;
    }
    cout << sum << "\n";

    lld sum2 = 0;
    for (int i = 0; i < v.size(); i++) {
        lld a = dfs(v[i], 75);
        cout << v[i] << " " << a << "\n";
        sum2 += a;
    }
    cout << sum2 << "\n";
    return 0;
}