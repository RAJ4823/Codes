// Link: https://leetcode.com/problems/greatest-sum-divisible-by-three

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: greatest-sum-divisible-by-three
 *  RUNTIME: 63 ms
 *  MEMORY: 38.7 MB
 *  DATE: 10-28-2023, 9:50:47 AM
 *
 */

// Solution:

class Solution {
public:
    int n = 0;
    int find(int i, int rem, vector<int> &nums, vector<vector<int>> &dp) {
        if(i >= n) 
            return (rem) ? INT_MIN : 0;
        if(dp[i][rem] != -1)
            return dp[i][rem];
        
        int take = nums[i] + find(i + 1, (rem + nums[i]) % 3, nums, dp);
        int nottake = find(i + 1, rem, nums, dp);
        return dp[i][rem] = max(take, nottake);
    }

    int filter(vector<int> &nums) {
        int sum = 0;
        vector<int> v;
        for(auto &val: nums) {
            if(val % 3 == 0)
                sum += val;
            else
                v.push_back(val);
        }
        nums = v;
        return sum;
    }
    int maxSumDivThree(vector<int>& nums) {
        int sum = filter(nums);
        n = nums.size();
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return sum + find(0, 0, nums, dp);
    }
};
