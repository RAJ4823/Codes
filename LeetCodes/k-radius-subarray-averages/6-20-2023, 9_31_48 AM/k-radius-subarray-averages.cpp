// Link: https://leetcode.com/problems/k-radius-subarray-averages

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: k-radius-subarray-averages
 *  RUNTIME: 275 ms
 *  MEMORY: 139 MB
 *  DATE: 6-20-2023, 9:31:48 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> avgs(n, -1);
        vector<long long> sum(n+1, 0);
        for(int i=1; i<=n; i++) {
            sum[i] = sum[i-1] + nums[i-1];
        }

        for(int i=k; i<n-k; i++) {
            avgs[i] = (sum[i+k+1] - sum[i-k]) / (2*k + 1);
        }
        return avgs;
    }
};
