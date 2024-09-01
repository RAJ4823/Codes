// Link: https://leetcode.com/problems/score-of-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: score-of-a-string
 *  RUNTIME: 1 ms
 *  MEMORY: 41.7 MB
 *  DATE: 6-1-2024, 8:19:59 AM
 *
 */

// Solution:

class Solution {
    public int scoreOfString(String s) {
        int sum = 0;
        for(int i=1; i<s.length(); i++) {
            sum += Math.abs((int)s.charAt(i-1) - (int)s.charAt(i));
        }
        return sum;
    }
}
