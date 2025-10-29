/*
Implement a SnapshotArray that supports the following interface:

SnapshotArray(int length) initializes an array-like data structure with the given length. Initially, each element equals 0.
void set(index, val) sets the element at the given index to be equal to val.
int snap() takes a snapshot of the array and returns the snap_id: the total number of times we called snap() minus 1.
int get(index, snap_id) returns the value at the given index, at the time we took the snapshot with the given snap_id

LINK: https://leetcode.com/problems/snapshot-array/description/
*/

// Brute Force Solution - Bad Complexity tho
class SnapshotArray {
public:
    vector<int> arr;
    map<int, vector<int>> history;
    int numSnaps = 0;
    SnapshotArray(int length) {
        arr.assign(length, 0);
    }
    
    void set(int index, int val) {
        arr[index] = val;
    }
    
    int snap() {
        history[numSnaps] = arr;
        return numSnaps++;
    }
    
    int get(int index, int snap_id) {
        return history[snap_id][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

// Better Solution:
// Where did we go wrong last time?
// 1
// Don't store the entire array every time a snapshot is taken
// Cuz there is only one change per snapshot -> just save the change
// SO
// For each index, keep a history of (snap_id, value) pairs!
// During retrieval we can binary-search the value valid at a given snap_id.
class SnapshotArray {
public:
    unordered_map<int, vector<pair<int, int>>> history;
    int snaps = 0;
    SnapshotArray(int length) {}
    
    void set(int index, int val) {
        auto &h = history[index];
        if(!h.empty() && h.back().first==snaps) h.back().second=val;
        else h.push_back({snaps, val});
    }
    
    int snap() {
        return snaps++;
    }
    
    int get(int index, int snap_id) {
        if(history.count(index)==0) return 0;

        auto &h = history[index];

        int l = 0, r = h.size()-1, ans = 0;

        while(l<=r){
            int m = l + (r-l)/2;
            if(h[m].first <= snap_id){
                ans = h[m].second;
                l = m+1;
            }
            else r = m-1;
        }
        return ans;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
