// Link: https://leetcode.com/problems/find-the-losers-of-the-circular-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-losers-of-the-circular-game
 *  RUNTIME: 10 ms
 *  MEMORY: 8.5 MB
 *  DATE: 5-25-2023, 9:22:50 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> vis(n, false);
        int curr = 1, i = 0; 

        while(!vis[curr-1]){
            vis[curr-1] = true;
            i += k;
            curr = (curr + i)%n;
            if(curr == 0) 
                curr = n;
        }

        vector<int> ans;
        for(int i = 0; i < vis.size(); ++i){
            if(!vis[i]) {
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
