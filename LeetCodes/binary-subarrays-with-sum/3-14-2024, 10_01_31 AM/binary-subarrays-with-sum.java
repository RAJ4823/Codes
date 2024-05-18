// Link: https://leetcode.com/problems/binary-subarrays-with-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-subarrays-with-sum
 *  RUNTIME: 3 ms
 *  MEMORY: 48.6 MB
 *  DATE: 3-14-2024, 10:01:31 AM
 *
 */

// Solution:

class Solution {
    public int numSubarraysWithSum(int[] nums, int goal) {
        int totalCount = 0;
        int sum = 0;
        int prefixSum[] = new int[nums.length + 1];
        prefixSum[0] = 1;
        
        for (int num : nums) {
            sum += num;
            if (sum >= goal) {
                totalCount += prefixSum[sum - goal];
            }
            prefixSum[sum]++;
        }
        
        return totalCount;
    }
}
