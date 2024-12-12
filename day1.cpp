#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> p1, p2;

int main() {
    int a, b;
    while (cin >> a >> b) {
        p1.push_back(a);
        p2.push_back(b);
    }
    sort(p1.begin(), p1.end());
    sort(p2.begin(), p2.end());
    cout << "size: " << p1.size() << "\n";
    int sum = 0;
    for (int i = 0; i < p1.size(); i++) {
        sum += abs(p1[i] - p2[i]);
    }
    cout << sum << "\n";

    // part 2
    int sum2 = 0;
    for (int i = 0; i < p1.size(); i++) {
        for (int j = 0; j < p1.size(); j++) {
            if (p1[i] == p2[j]) sum2 += p1[i];
        }
    }
    cout << sum2 << "\n";
    
    return 0;
}