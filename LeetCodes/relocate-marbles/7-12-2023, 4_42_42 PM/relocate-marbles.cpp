// Link: https://leetcode.com/problems/relocate-marbles

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: relocate-marbles
 *  RUNTIME: 413 ms
 *  MEMORY: 178.9 MB
 *  DATE: 7-12-2023, 4:42:42 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,bool> loc;
        int n = nums.size(), m = moveFrom.size();
        for(int i=0; i<n; i++) {
            loc[nums[i]] = true;
        }
        for(int i=0; i<m; i++) {
            loc[moveFrom[i]] = false;
            loc[moveTo[i]] = true;
        }
        vector<int> ans;
        for(auto &x: loc) {
            if(x.second) {
                ans.push_back(x.first);                
            }
        }
        return ans;
    }
};
