#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr.
*/

// Approach 1:
/*
Got the idea by observing the below:
arr = {11,81,94,43,3};
11 = 11
11 81 = 92
11 81 94 = 186
11 43 43 43 = 140
3 3 3 3 3 = 15
*/
int sumSubarrayMins(vector<int>& arr) {
    long long int sum = 0, minNum = INT32_MAX, prevsum = 0, maxNum = INT32_MIN;
    int n = arr.size();
    unordered_map<int,long long int> mpp;
    for(int i = 0; i<n; i++)
    {
        // 3 cases:
        if(arr[i]>minNum)
        {
            if(arr[i]>maxNum)
            {
                // arr[i] is the maximum among the encountered numbers
                maxNum = arr[i];
                prevsum = mpp[i-1]+arr[i];
            }
            else
            {
                // arr[i] is neither max nor min
                // Go from the arr[i] towards left to find the number less than arr[i]
                for(int j = i; j>=0; j--) 
                {
                    if(arr[j]<arr[i])
                    {
                        prevsum = mpp[j] + (i-j)*arr[i];
                        break;
                    }
                }
            }
        }
        else
        {
            // arr[i] is the min among the encountered numbers
            minNum = arr[i];
            prevsum = (i+1)*arr[i];
        }
        sum += prevsum;
        mpp.insert({i, prevsum});
    }
    return (sum % (1000000007));
}

// Approach 2:
// Using stacks
vector<int> nextSmaller(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;
    for(int i = n-1; i>=0; i--)
    {
        while(!st.empty() && nums[st.top()]>=nums[i])
        {
            st.pop();
        }
        if(st.empty()) ans[i]= n;
        else ans[i]= st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int>& nums) {
    stack<int> st;
    int n = nums.size();
    vector<int> ans(n);
    for(int i= 0; i<n; i++)
    {
        while(!st.empty() && nums[st.top()]>nums[i]) st.pop();
        if(st.empty()) ans[i] = -1;
        else ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int sumSubarrayMins2(vector<int>& arr)
{
    vector<int> pse = prevSmaller(arr), nse =  nextSmaller(arr);
    int n = arr.size();
    int tot = 0, mod = 1e9+7;
    for(int i = 0; i<n; i++)
    {
        int left = i - pse[i];
        int right = nse[i]-i;
        tot += (right*left*arr[i])%mod;
        tot = tot%mod;
    }
    return tot;
}

int main()
{
    vector<int> arr = {11,81,94,43,3};
    cout<<sumSubarrayMins(arr)<<endl;
    cout<<sumSubarrayMins2(arr)<<endl;
    return 0;
}

// OUTPUT:
// 444
// 444