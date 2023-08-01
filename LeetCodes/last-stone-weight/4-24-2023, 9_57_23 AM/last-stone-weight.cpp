// Link: https://leetcode.com/problems/last-stone-weight

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: last-stone-weight
 *  RUNTIME: 0 ms
 *  MEMORY: 7.7 MB
 *  DATE: 4-24-2023, 9:57:23 AM
 *
 */

// Solution:

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &val: stones) {
            pq.push(val);
        }
        while(pq.size() > 1) {
            int max1 = pq.top();
            pq.pop();
            int max2 = pq.top();
            pq.pop();
            int rem = max1 - max2;
            if(rem > 0) 
                pq.push(rem);
        }
        if(pq.empty())
            pq.push(0);
        return pq.top();
    }
};
