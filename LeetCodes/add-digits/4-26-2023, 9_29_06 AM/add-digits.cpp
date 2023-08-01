// Link: https://leetcode.com/problems/add-digits

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: add-digits
 *  RUNTIME: 0 ms
 *  MEMORY: 6 MB
 *  DATE: 4-26-2023, 9:29:06 AM
 *
 */

// Solution:

class Solution {
public:
    int addDigits(int num) {
        int n = num;
        while(n > 9) {
            int sum = 0;
            while(n > 0) {
                sum += n % 10;
                n /= 10;
            }
            n = sum;
        }
        return n;
    }
};
