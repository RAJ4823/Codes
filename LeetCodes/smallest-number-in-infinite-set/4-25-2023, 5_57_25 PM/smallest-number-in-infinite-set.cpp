// Link: https://leetcode.com/problems/smallest-number-in-infinite-set

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: smallest-number-in-infinite-set
 *  RUNTIME: 120 ms
 *  MEMORY: 46.2 MB
 *  DATE: 4-25-2023, 5:57:25 PM
 *
 */

// Solution:

class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        for(int i=1; i<=1000; i++) {
            s.insert(i);
        }
    }
    
    int popSmallest() {
        int mini = *s.begin();
        s.erase(mini);
        return mini;
    }
    
    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
