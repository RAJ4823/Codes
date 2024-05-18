// Link: https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: egg-drop-with-2-eggs-and-n-floors
 *  RUNTIME: 0 ms
 *  MEMORY: 40.3 MB
 *  DATE: 5-9-2024, 10:41:27 AM
 *
 */

// Solution:

class Solution {
    public int twoEggDrop(int n) {
        int steps = 0, i = 0;
        while(n > 0) {
            n -= i;
            steps++;
            i++;
        }
        return steps - 1;
    }
}
