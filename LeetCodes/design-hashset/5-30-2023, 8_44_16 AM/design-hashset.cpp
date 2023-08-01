// Link: https://leetcode.com/problems/design-hashset

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-hashset
 *  RUNTIME: 95 ms
 *  MEMORY: 43.6 MB
 *  DATE: 5-30-2023, 8:44:16 AM
 *
 */

// Solution:

class MyHashSet {
public:
    bitset<1000001> mp;
    MyHashSet() {
        mp.reset();
    }
    
    void add(int key) {
        mp.set(key);       
    }
    
    void remove(int key) {
        mp.set(key, 0);
    }
    
    bool contains(int key) {
        return mp[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
