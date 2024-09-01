// Link: https://leetcode.com/problems/crawler-log-folder

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: crawler-log-folder
 *  RUNTIME: 1 ms
 *  MEMORY: 42.3 MB
 *  DATE: 7-10-2024, 10:31:36 AM
 *
 */

// Solution:

class Solution {
    public int minOperations(String[] logs) {
        int depth = 0;
        for(String log: logs) {
            if(log.equals("../")) {
                depth = Math.max(0, depth - 1);
            } else if(log.equals("./")) {
                depth = depth;
            } else {
                depth = depth + 1;
            }
        }
        return depth;
    }
}
