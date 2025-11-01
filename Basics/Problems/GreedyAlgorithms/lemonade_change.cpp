/*
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). 
Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

LINK: https://leetcode.com/problems/lemonade-change/description/
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        map<int, int> mp;
        bool possi = true;
        for(int i = 0; i < bills.size(); i++){
            mp[bills[i]]++;
            int extra = bills[i]-5;
            if(extra == 5){
                if(mp[5]>0) mp[5]--;
                else{
                    possi = false;
                    break;
                }
            }
            else if(extra == 15){
                if(mp[10]>0){
                    mp[10]--;
                    if(mp[5]>0) mp[5]--;
                    else{
                        possi = false;
                        break;
                    }
                }
                else if(mp[5]>=3){
                    mp[5] -= 3;
                }
                else{
                    possi = false;
                    break;
                }
            }
        }
        return possi;
    }
};
