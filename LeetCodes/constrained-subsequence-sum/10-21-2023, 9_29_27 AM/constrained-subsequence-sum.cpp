// Link: https://leetcode.com/problems/constrained-subsequence-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: constrained-subsequence-sum
 *  RUNTIME: 310 ms
 *  MEMORY: 340.6 MB
 *  DATE: 10-21-2023, 9:29:27 AM
 *
 */

// Solution:

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;
        vector<int> dp(nums);
        dq.push_back(0);

        for(int i=1; i<n; i++) {
            while(!dq.empty() && dq.back() < i - k) {
                dq.pop_back();
            }
            dp[i] = max(dp[i], dp[dq.back()] + nums[i]);

            while(!dq.empty() && dp[dq.front()] <= dp[i]) {
                dq.pop_front();
            }
            dq.push_front(i);
        }
        int sum = *max_element(dp.begin(), dp.end());
        return sum;
    }
};
