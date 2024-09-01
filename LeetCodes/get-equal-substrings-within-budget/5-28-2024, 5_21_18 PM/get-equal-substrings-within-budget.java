// Link: https://leetcode.com/problems/get-equal-substrings-within-budget

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: get-equal-substrings-within-budget
 *  RUNTIME: 5 ms
 *  MEMORY: 43.2 MB
 *  DATE: 5-28-2024, 5:21:18 PM
 *
 */

// Solution:

class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int n = s.length();
        int[] diff = new int[n];

        for(int i=0; i<n; i++) {
            diff[i] = Math.abs((int)s.charAt(i) - (int)t.charAt(i));
        }
    
        int maxi = 0, i = 0, j = 0, sum = 0;
        while(i < n) {
            sum += diff[i];
            while(sum > maxCost && j <= i) {
                sum -= diff[j]; 
                j++;
            }
            maxi = Math.max(maxi, (i - j  + 1));
            i++;
        }   

        return maxi;
    }
}
