// Link: https://leetcode.com/problems/jump-game-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: jump-game-iii
 *  RUNTIME: 52 ms
 *  MEMORY: 31.1 MB
 *  DATE: 2-8-2023, 10:26:14 AM
 *
 */

// Solution:

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        queue<int> q;
        vector<bool> vis(n, false);

        q.push(start);
        vis[start] = true;

        while(!q.empty()) {
            int index = q.front();
            q.pop();

            if(arr[index] == 0) return true;
            
            int right = index + arr[index];
            int left = index - arr[index];

            if(right < n && !vis[right]) {
                vis[right] = true;
                q.push(index + arr[index]);
            }
            if(left >= 0 && !vis[left]) {
                vis[left] = true;
                q.push(index - arr[index]);
            }
        }  
        return false;
    }
};
