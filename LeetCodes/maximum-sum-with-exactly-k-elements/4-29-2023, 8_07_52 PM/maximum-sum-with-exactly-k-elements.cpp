// Link: https://leetcode.com/problems/maximum-sum-with-exactly-k-elements

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-sum-with-exactly-k-elements
 *  RUNTIME: 68 ms
 *  MEMORY: 73.1 MB
 *  DATE: 4-29-2023, 8:07:52 PM
 *
 */

// Solution:

class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto &val: nums)
                pq.push(val);
        
        int sum = 0;
        while(k > 0) {
            int x = pq.top();
            sum += x;
            pq.pop();
            pq.push(x + 1);
            k--;
        }
        return sum;
    }
};
