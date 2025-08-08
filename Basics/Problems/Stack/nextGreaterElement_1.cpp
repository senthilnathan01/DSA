#include<iostream>
#include<vector>
#include<stack>

using namespace std;

vector<int> findNGE(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i>=0; i--)
    {
        while(!st.empty() && st.top()<=nums[i])
        {
            st.pop();
        }
        if(st.empty()) ans[i]= -1;
        else ans[i]= st.top();
        st.push(nums[i]);
    }
    return ans;
}

int main()
{
    vector<int> nums = {1,3,4,2};
    vector<int> ans = findNGE(nums);
    for(int num: ans) cout<<num<<" ";
    return 0;
}

// OUTPUT:

// 3 4 -1 -1 


// Approach 2:
int main()
{
    int n; cin>>n;
    vector<int> a(n);
    vector<int> ans(n, -1);
    stack<int> st;

    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        while(!st.empty() && a[st.top()] < a[i])
        {
            ans[st.top()] = a[i];
            st.pop();
        }
        st.push(i);
    }

    for(auto num: ans) cout<<num<<" ";

    return 0;
}
