// Link: https://leetcode.com/problems/subarray-sums-divisible-by-k

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: subarray-sums-divisible-by-k
 *  RUNTIME: 65 ms
 *  MEMORY: 31.6 MB
 *  DATE: 1-19-2023, 5:45:26 PM
 *
 */

// Solution:

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int count = 0, sum = 0;

        freq[0] = 1;
        for(int i = 0; i<n; i++) {
            sum = (sum + nums[i]%k + k)%k;
            count += freq[sum];
            freq[sum]++;
        }
        return count;
    }
};
