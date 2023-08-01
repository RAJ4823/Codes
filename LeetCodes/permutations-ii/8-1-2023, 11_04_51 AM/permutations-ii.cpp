// Link: https://leetcode.com/problems/permutations-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: permutations-ii
 *  RUNTIME: 0 ms
 *  MEMORY: 9 MB
 *  DATE: 8-1-2023, 11:04:51 AM
 *
 */

// Solution:

class Solution {
public:
    void find(int i, int &n, vector<int> nums, vector<vector<int>> &ans) {
        if(i == n-1) {
            ans.push_back(nums);
            return;
        }
        for(int k=i; k<n; k++) {
            if(i != k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            find(i+1, n, nums, ans);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        find(0, n, nums, ans);
        return ans;

    }
};
