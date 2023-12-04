// Link: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-one-bit-operations-to-make-integers-zero
 *  RUNTIME: 3 ms
 *  MEMORY: 6.3 MB
 *  DATE: 11-30-2023, 11:48:24 AM
 *
 */

// Solution:

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n <= 1)
            return n;

        int count = 0;
        while((1 << count) <= n) 
            count++;
        
        int total = (1 << count) - 1;
        int next = n - (1 << (count - 1));
        return total - minimumOneBitOperations(next);
    }
};
