/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

LINK: https://leetcode.com/problems/find-median-from-data-stream/description/
*/
class MedianFinder {
public:
    priority_queue<int> maxHeap; // first half of the sorted array
    priority_queue<int, vector<int>, greater<int>> minHeap; // second half of the sorted array
    MedianFinder() {}
    
    void addNum(int num) {
        // Add num to the array
        if(maxHeap.empty()||num<maxHeap.top()) maxHeap.push(num);
        else minHeap.push(num);

        // Organise
        if(maxHeap.size()>minHeap.size()+1){
            minHeap.push(maxHeap.top());maxHeap.pop();
        }
        else if(maxHeap.size()<minHeap.size()){
            maxHeap.push(minHeap.top()); minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()==minHeap.size()){
            return (maxHeap.top()+minHeap.top())/2.0;
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
