#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
PROBLEM:
Given a non-empty array of integers nums, every element appears thrice except for one. Find that single one.
*/

// APPROACH 1:
// TC = O(N*BitsInTheMaxElement + n) The last n is for obtaining the max element
// SC = O(1)
/*
Quick Observation for the binary representation of the numbers in nums:
5 -> 1 0 1
5 -> 1 0 1
5 -> 1 0 1
6 -> 1 1 0
4 -> 1 0 0
4 -> 1 0 0
4 -> 1 0 0
-----------
(Add them up and divide by 3 to get the reminder)
     1 1 0 = 6
*/

int singleNumber1(vector<int> nums)
{
    
    int maxElement = *max_element(nums.begin(), nums.end());

    // Let's find the max bit index of this maxElement
    int maxBitIndex = 0;
    while(maxElement>(1<<maxBitIndex)) maxBitIndex++;
    maxBitIndex--;

    int singleNumber = 0;
    for(int BitIndex = 0; BitIndex<=maxBitIndex; BitIndex++)
    {
        int sum = 0;
        for(int num: nums) if(num & (1<<BitIndex)) sum++;
        singleNumber += (sum%3)*(1<<BitIndex);
    }
    return singleNumber;
}

// APPROACH 2:
// TC = O(n*logn + n/3)
// SC = O(1)
/*
Sort the number and check for triplets and return if the number is single
*/

int singleNumber2(vector<int> nums)
{
    sort(nums.begin(), nums.end());
    int size = nums.size();
    for(int i = 0; i<=size-3; i+=3) if(nums[i]!=nums[i+2]) return nums[i];
    return nums[size-1];
}

// Approach 3: (Optimal)
// Using the concept of buckets
// TC = O(n)
// SC = O(1)

int singleNumber3(vector<int> nums)
{
    int ones = 0;
    int twos = 0;
    for(int num: nums)
    {
        ones = (ones^num)&(~twos);
        twos = (twos^num)&(~ones);
    }
    return ones;
}

int main()
{
    vector<int> nums = {5,5,5,6,4,4,4};
    cout<<singleNumber1(nums)<<endl;
    cout<<singleNumber2(nums)<<endl;
    cout<<singleNumber3(nums);
}

// OUTPUT:
// 6
// 6
// 6
