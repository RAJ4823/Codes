// Link: https://leetcode.com/problems/k-th-symbol-in-grammar

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: k-th-symbol-in-grammar
 *  RUNTIME: 2 ms
 *  MEMORY: 6.2 MB
 *  DATE: 10-25-2023, 8:42:34 AM
 *
 */

// Solution:

class Solution {
public:
    int kthGrammar(int n, int k){
        return __builtin_popcount(k-1) & 1;
    }
};
