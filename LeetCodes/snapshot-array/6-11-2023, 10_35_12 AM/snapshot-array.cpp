// Link: https://leetcode.com/problems/snapshot-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: snapshot-array
 *  RUNTIME: 433 ms
 *  MEMORY: 163.3 MB
 *  DATE: 6-11-2023, 10:35:12 AM
 *
 */

// Solution:

class SnapshotArray {
public:
    unordered_map<int, unordered_map<int, int>> store;
    int snapId = 0, currId = 0;
    unordered_map<int,int> realId;

    SnapshotArray(int length) {
        store.clear();
    }
    
    void set(int index, int val) {
        if(snapId != currId) {
            store[snapId] = store[currId];
            currId = snapId;
        }
        store[currId][index] = val;
    }
    
    int snap() {
        realId[snapId] = currId;
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        return store[realId[snap_id]][index];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
