// Link: https://leetcode.com/problems/make-array-strictly-increasing

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: make-array-strictly-increasing
 *  RUNTIME: 280 ms
 *  MEMORY: 401 MB
 *  DATE: 6-17-2023, 10:12:14 AM
 *
 */

// Solution:

class Solution {
public: 
    vector<vector<int>> dp;
    int n, m;
    int MAX_OPS = 2001;
    int find(int i, int j, int prev, vector<int>& arr, vector<int>& vals) {
        j = upper_bound(vals.begin() + j, vals.end(), prev) - vals.begin();

        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j == m && arr[i] <= prev) return MAX_OPS;
        
        int replace = MAX_OPS, skip = MAX_OPS;
        if(j < m) replace = 1 + find(i+1, j+1, vals[j], arr, vals);
        if(arr[i] > prev) skip = find(i+1, j, arr[i], arr, vals);
            
        return dp[i][j] = min(skip, replace);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n = arr1.size();
        m = arr2.size();

        sort(arr2.begin(), arr2.end());
        dp.resize(MAX_OPS, vector<int> (MAX_OPS, -1));

        int ans = find(0, 0, -1, arr1, arr2);
        if(ans > n) return -1;
        return ans;
    }
};
