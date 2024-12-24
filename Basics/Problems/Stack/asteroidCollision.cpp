#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

/*
We are given an array asteroids of integers representing asteroids in a row. 
The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. 
If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
*/

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> ans;
    stack<int> st;
    int n = asteroids.size();
    int i = 0;

    while(i<n)
    {
        // Asteriods moving to the left that are not going to collide are added to the answer
        while(st.empty() && i<n && asteroids[i]<0)
        {
            ans.push_back(asteroids[i]);
            i++;   
        }

        // We are only going to have positive asteroids in the stack
        while(i<n && asteroids[i]>0)
        {
            st.push(asteroids[i]);
            i++;
        }

        // If the stack is not empty ->
        // Now that we encounter an asteroid moving to the left ->
        // Collision happens
        // Result will be a set of asteriods moving to the right or no asteriods
        if(i<n) //We still have asteriods
        {
            int num = asteroids[i]; //Asteriod moves to the left as we have already added the asteriods moving to the right to the answer array
            while(!st.empty() && abs(num) > st.top())
            {
                st.pop();
            }
            // After the above process either the stack is empty or it is not
            if(!st.empty())
            {
                if(abs(num) == st.top())
                {
                    st.pop();
                    num = 0;
                }
                else num = 0;
            }
            if(st.empty()) //If the stack is empty
            {
                if(num!=0)  ans.push_back(num);
            }
            i++;
        }       
    }
    vector<int> toadd;
    while(!st.empty())
    {
        toadd.push_back(st.top());
        st.pop();
    }
    reverse(toadd.begin(), toadd.end());
    ans.insert(ans.end(), toadd.begin(), toadd.end());
    return ans;
}

int main()
{
    vector<int> asteroids = {-2,-1,1,2};
    vector<int> ans = asteroidCollision(asteroids);
    for(int num: ans)cout<<num<<" ";
    return 0;
}

// OUTPUT:
// -2 -1 1 2