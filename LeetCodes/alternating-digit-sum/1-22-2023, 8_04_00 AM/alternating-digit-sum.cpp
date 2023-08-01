// Link: https://leetcode.com/problems/alternating-digit-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: alternating-digit-sum
 *  RUNTIME: 5 ms
 *  MEMORY: 5.8 MB
 *  DATE: 1-22-2023, 8:04:00 AM
 *
 */

// Solution:

class Solution {
public:
    int alternateDigitSum(int n) {
        int dig = 0, m = n;
        int sum1 = 0, sum2 = 0;
        int i = 0;
        while(m > 0) {
            dig = m%10;
            if(i%2 == 0) {
                sum1 += dig;
                sum2 -= dig;
            } else {
                sum1 -= dig;
                sum2 += dig;
            }
            m/=10;
            i++;
            
        }
        if(i%2 == 0) {
            return sum2;
        }
        return sum1;
    }
};
