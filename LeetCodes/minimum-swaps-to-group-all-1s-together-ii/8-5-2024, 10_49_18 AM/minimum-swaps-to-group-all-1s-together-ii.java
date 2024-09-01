// Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-swaps-to-group-all-1s-together-ii
 *  RUNTIME: 3 ms
 *  MEMORY: 59 MB
 *  DATE: 8-5-2024, 10:49:18 AM
 *
 */

// Solution:

class Solution {
    public int minSwaps(int[] nums) {
        int n = nums.length;

        int ones = 0;
        for(int num: nums) ones += num;
        
        if(ones == 0 || ones == n) return 0;

        int currOnes = 0;
        for(int i=0; i<ones; i++) currOnes += nums[i];

        int maxOnes = currOnes;
        for(int i=0; i<n; i++) {
            currOnes -= nums[i];
            currOnes += nums[(i + ones) % n];
            maxOnes = Math.max(maxOnes, currOnes);
        }

        return ones - maxOnes;
    }
}
