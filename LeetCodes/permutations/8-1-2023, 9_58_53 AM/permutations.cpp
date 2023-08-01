// Link: https://leetcode.com/problems/permutations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: permutations
 *  RUNTIME: 0 ms
 *  MEMORY: 7.8 MB
 *  DATE: 8-1-2023, 9:58:53 AM
 *
 */

// Solution:

class Solution {
public:
    set<vector<int>> s;
    void find(vector<int> &arr, unordered_set<int> &s, vector<int> &nums, vector<vector<int>> &ans) {
        if(arr.size() == nums.size()) {
            ans.push_back(arr);
            return;
        }

        for(auto &x: nums) {
            if(s.find(x) == s.end()) {
                arr.push_back(x);
                s.insert(x);
                find(arr, s, nums, ans);
                s.erase(x);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        unordered_set<int> s;
        vector<vector<int>> ans;
        find(arr , s, nums, ans);
        return ans;
    }
};
