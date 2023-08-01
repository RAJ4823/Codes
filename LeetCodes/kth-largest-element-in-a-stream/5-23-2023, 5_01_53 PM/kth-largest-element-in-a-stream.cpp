// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: kth-largest-element-in-a-stream
 *  RUNTIME: 1265 ms
 *  MEMORY: 22.2 MB
 *  DATE: 5-23-2023, 5:01:53 PM
 *
 */

// Solution:

class KthLargest {
public:
    multiset<int> s;
    int K;
    KthLargest(int k, vector<int>& nums) {
        for(auto &x: nums) {
            s.insert(-x);
        }
        K = k-1;
    }
    
    int add(int val) {
        s.insert(-val);
        auto it = s.begin();
        for (int i = 0; i < K; i++) it++;
        return -*it;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
