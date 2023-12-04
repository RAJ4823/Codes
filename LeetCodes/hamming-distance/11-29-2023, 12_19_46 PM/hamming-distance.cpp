// Link: https://leetcode.com/problems/hamming-distance

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: hamming-distance
 *  RUNTIME: 2 ms
 *  MEMORY: 6.2 MB
 *  DATE: 11-29-2023, 12:19:46 PM
 *
 */

// Solution:

class Solution {
public:
    int hammingDistance(int x, int y) {
        return __builtin_popcount(x ^ y);
    }
};
