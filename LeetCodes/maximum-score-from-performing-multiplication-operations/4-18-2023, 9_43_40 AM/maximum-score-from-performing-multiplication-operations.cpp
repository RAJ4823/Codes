// Link: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-score-from-performing-multiplication-operations
 *  RUNTIME: 161 ms
 *  MEMORY: 83.6 MB
 *  DATE: 4-18-2023, 9:43:40 AM
 *
 */

// Solution:

class Solution {
public:
    int n = 0, m = 0;
    vector<vector<int>> dp;
    int find(int s, int e, int i, vector<int>& nums, vector<int>& mult) {
        if(s > e) return 0;
        if(i >=m) return 0;
        if(dp[i][s] != -1) return dp[i][s];

        int first = nums[s] * mult[i] + find(s+1, e, i+1, nums, mult);
        int second= nums[e] * mult[i] + find(s, e-1, i+1, nums, mult);
        
        return dp[i][s] = max(first, second);
    }
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        n = nums.size();
        m = mult.size();
        dp.resize(m, vector<int> (m, -1));
        return find(0, n-1, 0, nums, mult);
    }
};
