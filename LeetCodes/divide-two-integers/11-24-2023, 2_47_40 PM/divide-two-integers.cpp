// Link: https://leetcode.com/problems/divide-two-integers

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: divide-two-integers
 *  RUNTIME: 3 ms
 *  MEMORY: 6.4 MB
 *  DATE: 11-24-2023, 2:47:40 PM
 *
 */

// Solution:

class Solution {
public:
    int divide(long a, long b) {
        return (a/b) > INT_MAX ? INT_MAX : (a/b);
    }
};
