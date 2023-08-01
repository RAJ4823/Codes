// Link: https://leetcode.com/problems/the-number-of-beautiful-subsets

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: the-number-of-beautiful-subsets
 *  RUNTIME: 34 ms
 *  MEMORY: 33.7 MB
 *  DATE: 3-23-2023, 2:13:01 PM
 *
 */

// Solution:

class Solution {
public:
    int dp[21][21] = {};
    int dfs(int i, int last_i, vector<int> &arr, int k) {
        if (i == arr.size())
            return 1;
        if (dp[i][last_i] == 0)
            dp[i][last_i] = dfs(i + 1, last_i, arr, k) + 
            (arr[i] - arr[last_i] == k ? 0 : dfs(i + 1, i, arr, k));
        return dp[i][last_i];
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> arr;
        unordered_map<int, vector<int>> m;
        for (int n : nums)
            m[n % k].push_back(n);
        for (auto &[mod, cnt] : m) {
            sort(begin(cnt), end(cnt));
            arr.insert(end(arr), begin(cnt), end(cnt));
        }
        return dfs(0, arr.size() - 1, arr, k) - 1;
    }
};
