// Link: https://leetcode.com/problems/maximize-happiness-of-selected-children

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximize-happiness-of-selected-children
 *  RUNTIME: 37 ms
 *  MEMORY: 61.2 MB
 *  DATE: 5-9-2024, 10:28:40 AM
 *
 */

// Solution:

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long sum = 0, j = 0;
        for(int i = happiness.length - 1; i > happiness.length - 1 - k; i--) {
            sum += (long)Math.max(happiness[i] - j, 0);
            j++;
        }
        return sum;
    }
}
