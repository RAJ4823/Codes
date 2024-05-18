// Link: https://leetcode.com/problems/maximize-happiness-of-selected-children

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximize-happiness-of-selected-children
 *  RUNTIME: 34 ms
 *  MEMORY: 61.5 MB
 *  DATE: 5-9-2024, 10:30:41 AM
 *
 */

// Solution:

class Solution {
    public long maximumHappinessSum(int[] happiness, int k) {
        Arrays.sort(happiness);
        long sum = 0, j = 0;
        for(int i = happiness.length - 1; i > happiness.length - 1 - k; i--) {
            if(happiness[i] - j > 0) 
                sum += happiness[i] - j;
            j++;
        }
        return sum;
    }
}
