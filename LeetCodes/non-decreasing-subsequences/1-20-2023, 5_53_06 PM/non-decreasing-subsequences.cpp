// Link: https://leetcode.com/problems/non-decreasing-subsequences

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: non-decreasing-subsequences
 *  RUNTIME: 87 ms
 *  MEMORY: 22.4 MB
 *  DATE: 1-20-2023, 5:53:06 PM
 *
 */

// Solution:

class Solution {
public:
    void find(int i, int n, vector<int> &nums, vector<int> &arr, set<vector<int>> &s) {
        if(i == n) {
            if(arr.size() >= 2) s.insert(arr);
            return;
        }

        if(arr.size() == 0 || arr.back() <= nums[i]) {
            arr.push_back(nums[i]);
            find(i+1, n, nums, arr, s);
            arr.pop_back();
        }
        find(i+1, n, nums, arr, s);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> s;
        vector<int> arr;

        find(0, n, nums, arr, s);

        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
