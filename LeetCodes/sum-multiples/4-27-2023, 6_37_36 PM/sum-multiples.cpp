// Link: https://leetcode.com/problems/sum-multiples

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-multiples
 *  RUNTIME: 4 ms
 *  MEMORY: 5.9 MB
 *  DATE: 4-27-2023, 6:37:36 PM
 *
 */

// Solution:

class Solution {
public:
    int sumOfMultiples(int n) {
        int sum =0;
        for(int i=1; i<=n; i++) {
            if(i % 3 == 0) sum += i;
            else if(i % 5 == 0) sum += i;
            else if(i % 7 == 0) sum += i;
        }
        return sum;
    }
};
