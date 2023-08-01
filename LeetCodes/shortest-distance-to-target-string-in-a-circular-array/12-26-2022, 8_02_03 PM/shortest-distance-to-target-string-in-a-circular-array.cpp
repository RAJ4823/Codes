// Link: https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-distance-to-target-string-in-a-circular-array
 *  RUNTIME: 31 ms
 *  MEMORY: 14.6 MB
 *  DATE: 12-26-2022, 8:02:03 PM
 *
 */

// Solution:

class Solution {
public:
    int closetTarget(vector<string>& words, string target, int s) {
         int n = words.size(), ans = INT_MAX;
        
        for(int i = 0; i < n; i++) {
            if(words[i] == target) {
                int dist_right =  abs(s - i);
                int dist_left = abs(n- dist_right);
                ans = min(ans, min(dist_right, dist_left)); 
            }
                
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};
