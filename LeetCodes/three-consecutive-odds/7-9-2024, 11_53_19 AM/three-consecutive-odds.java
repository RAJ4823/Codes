// Link: https://leetcode.com/problems/three-consecutive-odds

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: three-consecutive-odds
 *  RUNTIME: 0 ms
 *  MEMORY: 42.4 MB
 *  DATE: 7-9-2024, 11:53:19 AM
 *
 */

// Solution:

class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        for(int i=0; i<arr.length; i++) {
            if(i + 2 >= arr.length) return false;
            if((arr[i] & 1) == 1 && (arr[i+1] & 1) == 1 && (arr[i+2] & 1) == 1)
                return true;
        }
        return false;
    }
}
