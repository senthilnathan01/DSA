/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Link: https://leetcode.com/problems/maximal-rectangle/description/
*/

class Solution {
public:
    int largestRec(vector<int> &histo){
        int n = histo.size();
        stack<int> st;
        int maxA = 0;
        for(int i = 0; i <= n; i++){
            while(!st.empty() && (i == n || histo[st.top()] >= histo[i])){
                int height = histo[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i - st.top() -1;
                maxA = max(maxA, width*height);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]=='1') height[j]++;
                else height[j] = 0;
            }
            ans = max(ans, largestRec(height));
        }
        return ans;
    }
};
