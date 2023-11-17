// Link: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: determine-if-a-cell-is-reachable-at-a-given-time
 *  RUNTIME: 2 ms
 *  MEMORY: 6.2 MB
 *  DATE: 11-8-2023, 11:20:25 AM
 *
 */

// Solution:

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diffx = abs(sx - fx);
        int diffy = abs(sy - fy);
        if(!diffx && !diffy && t == 1) 
            return false;
        return max(diffx, diffy) <= t;
    }
};
