// Link: https://leetcode.com/problems/k-items-with-the-maximum-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: k-items-with-the-maximum-sum
 *  RUNTIME: 4 ms
 *  MEMORY: 6 MB
 *  DATE: 3-26-2023, 11:42:45 AM
 *
 */

// Solution:

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        if(k <= numOnes + numZeros)
            return min(k, numOnes);
        else {
            int count = numOnes + numZeros;
            int diff = k - count;
            return numOnes - diff;
        }
    }
};
