#include <bits/stdc++.h>
using namespace std;

int main() {
    string t; cin>>t;
    int n = t.size();

    // precomputed
    vector<int> prefixT(n + 1, 0);
    for (int i = 0; i < n; i++) prefixT[i + 1] = prefixT[i] + (t[i] == 't');

    vector<int> pos; // positions of't'
    for (int i = 0; i < n; i++) if (t[i] == 't') pos.push_back(i);

    if (pos.size() < 2) {
        cout << "0.0000000000000000\n";
        return 0;
    }

    double maxAns = 0.0;
    
    // This is O(N^2)
    // Try all pairs of 't' positions as start and end
    for (int i = 0; i < (int)pos.size(); i++) {
        for (int j = i + 1; j < (int)pos.size(); j++) {
            int startPos = pos[i];
            int endPos = pos[j];
            if (endPos - startPos + 1 >= 3) {
                int countTinside = prefixT[endPos] - prefixT[startPos + 1];
                int lenInside = endPos - startPos - 1;
                double rate = (double)countTinside / lenInside;
                maxAns = max(maxAns, rate);
            }
        }
    }

    cout << fixed << setprecision(16) << maxAns << "\n";
    return 0;
}
