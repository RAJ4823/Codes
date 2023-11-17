// Link: https://leetcode.com/problems/sum-of-subarray-ranges

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-of-subarray-ranges
 *  RUNTIME: 75 ms
 *  MEMORY: 10.7 MB
 *  DATE: 11-9-2023, 7:11:17 PM
 *
 */

// Solution:

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for(int i=0; i<n; i++) {
            int maxi = nums[i], mini = nums[i];
            for(int j=i+1; j<n; j++) {
                maxi = max(maxi, nums[j]);
                mini = min(mini, nums[j]);
                sum += (long long)(maxi - mini);
            }
        }
        return sum;
    }
};
