// Link: https://leetcode.com/problems/jump-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: jump-game
 *  RUNTIME: 771 ms
 *  MEMORY: 50.4 MB
 *  DATE: 12-26-2022, 7:41:25 PM
 *
 */

// Solution:

class Solution {
private:
    bool dfs(int i, vector<int> &nums, vector<int> &dp, int n) {
        if(i >= n)          return false;
        if(i == n-1)        return true;
        if(nums[i] == 0)    return false;
        if(dp[i] != -1) return dp[i];

        for(int j = 1; j<=nums[i]; j++) {
            if(i+j >= n)        
                continue;
            if(dfs(i+j, nums, dp, n)) 
                return dp[i] = true;
        }
        return dp[i] = false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        // return dfs(0, nums, dp, n);
        dp[n-1] = true;

        for(int i = n-2; i >= 0; i--) {
            if(nums[i] == 0) {
                dp[i] = false;
            }
            else {
                bool flag = false;
                for(int j = 1; j <= min(nums[i], (n-i)); j++) {
                    if(dp[i+j]) {
                        flag = true;
                        break;
                    }
                }
                dp[i] = flag;
            }
        }
        return dp[0];
    }
};