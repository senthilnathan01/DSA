#include <bits/stdc++.h>
using namespace std;

/*
The goal is to find the smallest K where both A and B can miss at least one number from 0 to K.

If A and B together don't have all numbers from 0 to M, both miss at least one, satisfying the condition.

When all 0 to M are in the total set, check if we can avoid one array containing all of them.

Now, 

To miss x in A, all occurrences of x must be assigned to B in their respective columns.

If a column has both values as x, it's impossible to miss x in either A or B.

Similarly, missing y in B requires putting all y to A, with the same condition: no double y column.

Thus => We need an assignment where some x in S is missing in A and some y in S is missing in B, possibly different.

Final Implementation Strategy:
Combine all unique numbers from A and B into a set (appears). This shows what's available across both arrays.

Identify numbers where A[i] = B[i] (forced). These must stay in both arrays (swapping doesn't change them).

Find the smallest non-negative number not in appears (union MEX or overall MEX). This is the baseline if we can't control misses.

List non-negative numbers in appears that aren't forced (can be assigned to A or B via swaps). Sort them.

If fewer than 2 flexible numbers, we can't make both arrays miss different small numbers, so answer is the overall MEX.

Otherwise, take the minimum of the overall MEX and the second smallest flexible number (flex[1]). Why? We can make A miss the smallest flexible (e.g., 0) and B miss the next (e.g., 2), so max=2.

The smaller of the overall MEX (if flexibility is limited) or the second smallest flexible number (if we can assign misses to balance MEXes).
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < n; i++) cin >> B[i];

    set<int> appears;
    set<int> forced;

    for (int i = 0; i < n; i++) {
        appears.insert(A[i]);
        appears.insert(B[i]);
        if (A[i] == B[i]) forced.insert(A[i]);
    }

    // overall mex
    int mex = 0;
    while (appears.count(mex)) mex++;

    vector<int> myVec;
    for (auto x : appears) {
        if(forced.count(x) == 0) myVec.push_back(x);
    }
    sort(myVec.begin(), myVec.end());

    int ans;
    if (myVec.size() < 2) ans = mex;
    else ans = min(mex, myVec[1]);
    cout << ans << endl;
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}

