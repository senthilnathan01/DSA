/*
You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. 
  This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the 
kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

Implement the KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far.

LINK: https://leetcode.com/problems/kth-largest-element-in-a-stream/description/
*/

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

// Another way to do this without min heap is to use an array
// sort it first
// because this is sorted, it becomes easier to insert new element in O(logN) time
// getting the kth largest is O(1) as we are using array 
// and just need to return array[array.size()-k] (if sorted in ascending)
class KthLargest {
public:
    vector<int> stream;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) stream.push_back(num);
        sort(stream.begin(), stream.end());
    }
    
    int add(int val) {
        int index = getIndex(val);
        stream.insert(stream.begin()+index, val);
        return stream[stream.size()-k];
    }

private:
    int getIndex(int val){
        int l = 0, r = stream.size()-1;
        // Do BS
        while(l<=r){
            int m = (l+r)/2;
            int midVal = stream[m];
            if(midVal==val) return m;
            if(midVal > val) r = m-1;
            else l = m+1;
        }
        // left has moved past all elements smaller than val
        // current position of left is the one to be returned
        return l;
    }
};

// Using Priority Queue
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) add(num);
    }
    
    int add(int val) {
        if(pq.size()<k||pq.top()<val){
            pq.push(val);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
