// Link: https://leetcode.com/problems/design-hashmap

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-hashmap
 *  RUNTIME: 124 ms
 *  MEMORY: 208.4 MB
 *  DATE: 10-4-2023, 10:53:48 AM
 *
 */

// Solution:

class MyHashMap {
public:
    vector<int> MAP;
    MyHashMap() {
        MAP.resize(1e6 + 5, -1);
    }
    void put(int key, int val) {
        MAP[key] = val;
    }
    int get(int key) {
        return MAP[key];
    }
    void remove(int key) {
        MAP[key] = -1;
    }
};
