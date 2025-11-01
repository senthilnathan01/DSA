/*
Given two arrays, val[] and wt[] , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, 
determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

LINK: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1
*/
class Solution {
  public:
    struct Item{
        int value;
        int weight;
    };
    
    static bool cmp(Item a, Item b){
        double r1 = (double) a.value / a.weight;
        double r2 = (double) b.value / b.weight;
        return r1 > r2;
    }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<Item> items(n);
        
        for(int i = 0; i < n; i++){
            items[i] = {val[i], wt[i]};
        }
        
        sort(items.begin(), items.end(), cmp);
        
        int i = 0;
        int rem = capacity;
        double ans = 0.0;
        while(i < n && rem > 0){
            if(items[i].weight <= rem){
                ans += items[i].value;
                rem -= items[i].weight;
            }
            else{
                double ratio = (double) rem / items[i].weight;
                ans += items[i].value * ratio;
                break;
            }
            i++;
        }
        return ans;
    }
};

