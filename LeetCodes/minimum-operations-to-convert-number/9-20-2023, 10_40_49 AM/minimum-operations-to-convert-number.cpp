// Link: https://leetcode.com/problems/minimum-operations-to-convert-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-operations-to-convert-number
 *  RUNTIME: 493 ms
 *  MEMORY: 134.5 MB
 *  DATE: 9-20-2023, 10:40:49 AM
 *
 */

// Solution:

class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> vis(1001, false);
        queue<int> q;

        q.push(start);

        int steps = 0, n = nums.size();
        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                int value = q.front();
                q.pop();

                if(value == goal) return steps;
                if(value < 0 || value > 1000 || vis[value]) continue;
                
                vis[value] = true;
                for(auto &x: nums) {
                    q.push(value + x);
                    q.push(value - x);
                    q.push(value ^ x);
                }
            }
            steps++;
        }
        return -1;
    }
};
