/*
THE TRICK TO SOLVING THIS IS JUST ACTUALLY READING THE QUESTION PROPERLY. PAY ATTENTION!

You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxesi is the number of boxes of type i.
numberOfUnitsPerBoxi is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.

LINK:https://leetcode.com/problems/maximum-units-on-a-truck/description/
*/  
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });
        int ans = 0;
        int num;
        for(auto b: boxTypes){
            if(truckSize==0) break;
            num = min(b[0], truckSize);
            truckSize -= num;
            ans += num*b[1];
        }
        return ans;
    }
};
