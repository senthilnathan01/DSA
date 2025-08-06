#include <iostream>
using namespace std;

// Key = covert gold to silver (rule 1 == rule 2)
void solve() {
    long long a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    long long v1 = 5 * a1 + b1;
    long long v2 = 5 * a2 + b2;

    if (v1 >= v2 && (v1 - v2) % 6 == 0) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();

    return 0;
}
