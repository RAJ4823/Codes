// Link: https://leetcode.com/problems/combination-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: combination-sum
 *  RUNTIME: 40 ms
 *  MEMORY: 36.3 MB
 *  DATE: 5-31-2023, 10:37:16 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> ans;
    void find(int i, int tar, vector<int> &arr, vector<int> v) {
        if(i < 0 || tar < 0) return;
        if(tar == 0) {
            ans.push_back(v);
            return;
        }
        if(tar >= arr[i]) {
            v.push_back(arr[i]);
            find(i, tar-arr[i], arr, v);
            v.pop_back();
        }
        find(i-1, tar, arr, v);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> v;
        find(n-1, target, arr, v);
        return ans;
    }
};
