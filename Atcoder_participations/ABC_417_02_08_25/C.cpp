#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    
    vector<long long> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    unordered_map<long long, int> freq;
    
    long long count = 0;
    
    for (int j = 1; j <= n; j++) {
        long long target = (long long)j - a[j];
        
        if (freq.count(target)) {
            count += freq[target];
        }
        
        long long val = (long long)j + a[j];
        
        freq[val]++;
    }
    
    cout << count;
    
    return 0;
}
