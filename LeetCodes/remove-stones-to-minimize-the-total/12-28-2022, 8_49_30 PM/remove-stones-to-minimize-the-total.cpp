// Link: https://leetcode.com/problems/remove-stones-to-minimize-the-total

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-stones-to-minimize-the-total
 *  RUNTIME: 724 ms
 *  MEMORY: 105.1 MB
 *  DATE: 12-28-2022, 8:49:30 PM
 *
 */

// Solution:

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> pq;
        for(int i=0; i<n; i++) {
            pq.push(piles[i]);
        }

        while(k > 0 && !pq.empty()) {
            int val = pq.top();
            pq.pop();
            if(val == 0) continue;

            if(val%2) val++; 
            val /= 2;
            pq.push(val);
            k--;
        }

        int ans = 0;
        while(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};
