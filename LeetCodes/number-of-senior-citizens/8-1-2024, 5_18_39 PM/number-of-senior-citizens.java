// Link: https://leetcode.com/problems/number-of-senior-citizens

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-senior-citizens
 *  RUNTIME: 1 ms
 *  MEMORY: 42.4 MB
 *  DATE: 8-1-2024, 5:18:39 PM
 *
 */

// Solution:

class Solution {
    public int countSeniors(String[] details) {
        int ans = 0;
        for (var x : details) {
            int age = Integer.parseInt(x.substring(11, 13));
            if (age > 60) {
                ++ans;
            }
        }
        return ans;
    }
}
