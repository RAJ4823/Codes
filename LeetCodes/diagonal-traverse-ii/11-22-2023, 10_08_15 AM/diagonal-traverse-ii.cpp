// Link: https://leetcode.com/problems/diagonal-traverse-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: diagonal-traverse-ii
 *  RUNTIME: 197 ms
 *  MEMORY: 97.6 MB
 *  DATE: 11-22-2023, 10:08:15 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        vector<int> ans;
        int maxi = 0;

        for(int i=0; i<nums.size(); i++) {
            for(int j=0; j<nums[i].size(); j++) {
                mp[i+j].push_back(nums[i][j]);
                maxi = max(maxi, i+j);
            }
        }

        for(int sum = 0; sum <= maxi; sum++) {
            for(auto it = mp[sum].rbegin(); it != mp[sum].rend(); it++) {
                ans.push_back(*it);
            }
        }
        return ans;
    }
};
