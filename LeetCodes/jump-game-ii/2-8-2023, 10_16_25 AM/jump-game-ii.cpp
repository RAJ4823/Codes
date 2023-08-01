// Link: https://leetcode.com/problems/jump-game-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: jump-game-ii
 *  RUNTIME: 389 ms
 *  MEMORY: 18.2 MB
 *  DATE: 2-8-2023, 10:16:25 AM
 *
 */

// Solution:

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        queue<pair<int,int>> q;
        vector<int> minJumps(n, INT_MAX);

        q.push({0, 0});
        minJumps[0] = 0;

        while(!q.empty()) {
            int index = q.front().first;
            int jumps = q.front().second;
            q.pop();

            if(index == n-1) break;
            for(int j = 0; j <= nums[index] && index + j < n; j++) {
                int next = j + index;
                if(minJumps[index] + 1 < minJumps[next]) {
                    minJumps[next] = minJumps[index] + 1;
                    q.push({next, minJumps[next]});
                }
            }
        }

        return minJumps[n-1];
    }
};
