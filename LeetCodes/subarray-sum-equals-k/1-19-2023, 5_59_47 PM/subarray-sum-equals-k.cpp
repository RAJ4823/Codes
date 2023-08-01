// Link: https://leetcode.com/problems/subarray-sum-equals-k

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: subarray-sum-equals-k
 *  RUNTIME: 107 ms
 *  MEMORY: 47 MB
 *  DATE: 1-19-2023, 5:59:47 PM
 *
 */

// Solution:

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, n = nums.size(), ans = 0;
        unordered_map<int,int> freq;
        freq[0] = 1;
        for(int i=0; i<n; i++) {
            sum += nums[i];
            ans += freq[sum - k];
            freq[sum]++;
        }
        return ans;
    }
};
