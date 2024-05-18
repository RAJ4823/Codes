// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-nesting-depth-of-the-parentheses
 *  RUNTIME: 0 ms
 *  MEMORY: 41.3 MB
 *  DATE: 4-4-2024, 5:17:17 PM
 *
 */

// Solution:

class Solution {
    public int maxDepth(String s) {
        int depth = 0, ans = 0;
        for (int i=0; i<s.length(); i++) {
            depth += (s.charAt(i) == '(') ? 1 : 0;
            depth -= (s.charAt(i) == ')') ? 1 : 0;
            ans = Integer.max(depth, ans);
        }
        return ans;
    }
}
