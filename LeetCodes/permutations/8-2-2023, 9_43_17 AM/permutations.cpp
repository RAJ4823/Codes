// Link: https://leetcode.com/problems/permutations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: permutations
 *  RUNTIME: 4 ms
 *  MEMORY: 7.5 MB
 *  DATE: 8-2-2023, 9:43:17 AM
 *
 */

// Solution:

class Solution {
public:
    void find(vector<int> &arr, int mask, int &n, vector<int> &nums, vector<vector<int>> &ans) {
        if(mask == ((1<<n)-1)) {
            ans.push_back(arr);
            return;
        }

        for(int i=0; i<n; i++) {
            if((mask & (1 << i)) == 0) {
                arr.push_back(nums[i]);
                find(arr, (mask | (1 << i)), n, nums, ans);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        vector<vector<int>> ans;
        find(arr, 0, n, nums, ans);
        return ans;
    }
};
