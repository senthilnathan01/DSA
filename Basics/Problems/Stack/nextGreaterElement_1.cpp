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