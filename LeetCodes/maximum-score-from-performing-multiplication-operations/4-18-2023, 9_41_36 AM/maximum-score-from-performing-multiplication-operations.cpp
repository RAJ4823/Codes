// Link: https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-score-from-performing-multiplication-operations
 *  RUNTIME: 1466 ms
 *  MEMORY: 201.8 MB
 *  DATE: 4-18-2023, 9:41:36 AM
 *
 */

// Solution:

class Solution {
public:
    int n = 0, m = 0;
    unordered_map<string, int> dp;
    int find(int s, int e, int i, vector<int>& nums, vector<int>& mult) {
        if(s > e) return 0;
        if(i >=m) return 0;
        string key = to_string(s) + "|" + to_string(e);
        if(dp.find(key) != dp.end()) return dp[key];

        int first = nums[s] * mult[i] + find(s+1, e, i+1, nums, mult);
        int second= nums[e] * mult[i] + find(s, e-1, i+1, nums, mult);
        
        return dp[key] = max(first, second);
    }
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        n = nums.size();
        m = mult.size();
        return find(0, n-1, 0, nums, mult);
    }
};
