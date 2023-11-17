// Link: https://leetcode.com/problems/poor-pigs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: poor-pigs
 *  RUNTIME: 0 ms
 *  MEMORY: 6.5 MB
 *  DATE: 10-29-2023, 9:23:28 PM
 *
 */

// Solution:

class Solution {
public:
    int poorPigs(int buckets, int timeDetect, int timeTest) {
        int choices = (timeTest / timeDetect) + 1;
        return ceil(log2(buckets)/log2(choices));
    }
};
