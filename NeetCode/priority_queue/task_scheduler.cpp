/*
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. 
  Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, 
but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

  LINK: https://leetcode.com/problems/task-scheduler/description/
*/

// Approach 1 - Observation and simple formula
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char, int> mpp;
        int maxFreq = 0;
        for(auto ch: tasks){
            mpp[ch]++;
            maxFreq = max(maxFreq, mpp[ch]);
        }

        int extras = 0;
        for(auto p: mpp) if(p.second==maxFreq) extras++;

        return max((maxFreq-1)*(n+1) + extras, (int)tasks.size());
    }
};

// Using Priority Queue
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // store char -> frequencies
        unordered_map<char, int> freq;
        for(char t: tasks) freq[t]++;

        // max Heap of frequencies
        priority_queue<int> mH;
        for(auto [ch, f]: freq) mH.push(f);

        int time =0;
        while(!mH.empty()){
            vector<int> temp; // tasks to insert later
            int cycle = n+1; // one full cooldown cycle

            // process upto n+1 tasks
            while(cycle > 0 && !mH.empty()){
                int f = mH.top(); mH.pop();
                f--;
                if(f>0) temp.push_back(f);
                time++;
                cycle--;
            }

            // push remaining tasks back into heap
            for(int f : temp) mH.push(f);

            // if heap is not empty, add the idle times for that cycle
            // add cycle itself, as cycle holds the idle time value
            if(!mH.empty()) time += cycle;
        }
        return time;
    }
};
