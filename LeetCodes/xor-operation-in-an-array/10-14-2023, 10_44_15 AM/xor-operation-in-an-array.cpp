// Link: https://leetcode.com/problems/xor-operation-in-an-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: xor-operation-in-an-array
 *  RUNTIME: 2 ms
 *  MEMORY: 6.2 MB
 *  DATE: 10-14-2023, 10:44:15 AM
 *
 */

// Solution:

class Solution {
public:
    int xorOperation(int n, int start) {
        int x = start;
        for(int i=1; i<n; i++) {
            x ^= (start + 2 * i);
        }
        return x;
    }
};
