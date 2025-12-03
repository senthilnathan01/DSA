// #include <bits/stdc++.h>
// using namespace std;

// bool isInvalid(string i){
//     if(i.length()&1) return false;
//     string num1 = i.substr(0, i.length()/2);
//     string num2 = i.substr(i.length()/2, i.length()/2);
//     if(num1!=num2) return false;
//     if(isInvalid(num1)) return false;
//     return true;
// }

// int main() {
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);

//     string inputLine;
//     cin>>inputLine;
//     long long ans = 0;
    
//     stringstream ss(inputLine);
//     string token;
//     while(getline(ss, token, ',')){
//         stringstream st(token);
//         string num;
//         vector<long long> nums;
//         while(getline(st, num, '-')){
//             nums.push_back(stoll(num));
//         }
//         for(long long i = nums[0]; i <=nums[1]; i++){
//             if(isInvalid(to_string(i))) ans += i; 
//         }
//     }
//     cout<<ans;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // If you're using files, keep these; otherwise, remove them.
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string line;
    if (!getline(cin, line)) {
        cout << 0 << '\n';
        return 0;
    }

    // 1. Parse ranges
    vector<pair<long long,long long>> ranges;
    string token;
    stringstream ss(line);
    long long maxR = 0;

    while (getline(ss, token, ',')) {
        if (token.empty()) continue;
        size_t dash = token.find('-');
        long long L, R;
        if (dash == string::npos) {
            long long x = stoll(token);
            L = R = x;
        } else {
            L = stoll(token.substr(0, dash));
            R = stoll(token.substr(dash + 1));
        }
        if (L > R) swap(L, R);
        ranges.emplace_back(L, R);
        maxR = max(maxR, R);
    }

    if (ranges.empty()) {
        cout << 0 << '\n';
        return 0;
    }

    // 2. Precompute all invalid IDs <= maxR
    vector<long long> invalids;
    int maxDigits = (int)to_string(maxR).size();

    // powers of 10 up to 10^18
    long long p10[19];
    p10[0] = 1;
    for (int i = 1; i < 19; ++i) p10[i] = p10[i-1] * 10LL;

    for (int totalLen = 2; totalLen <= maxDigits; totalLen += 2) {
        int half = totalLen / 2;
        long long start = p10[half - 1];  // first digit of X is nonzero
        long long end   = p10[half];      // X in [start, end)

        for (long long h = start; h < end; ++h) {
            long long n = h * p10[half] + h;  // concatenate X with X
            if (n > maxR) break;
            invalids.push_back(n);
        }
    }

    sort(invalids.begin(), invalids.end());

    // 3. Sum invalid IDs inside each range
    long long ans = 0;
    for (auto range : ranges) {
        auto L = range.first;
        auto R = range.second;
        auto itL = lower_bound(invalids.begin(), invalids.end(), L);
        auto itR = upper_bound(invalids.begin(), invalids.end(), R);
        for (auto it = itL; it != itR; ++it) {
            ans += *it;
        }
    }

    cout << ans << '\n';
    return 0;
}
