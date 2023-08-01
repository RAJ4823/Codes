// Link: https://leetcode.com/problems/count-the-digits-that-divide-a-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-the-digits-that-divide-a-number
 *  RUNTIME: 0 ms
 *  MEMORY: 5.9 MB
 *  DATE: 1-1-2023, 8:03:12 AM
 *
 */

// Solution:

class Solution {
public:
    int countDigits(int num) {
        int n = num, count = 0, dig;
        while(num > 0) {
            dig = num%10;
            num/=10;
            if(n%dig == 0) count++;
        }
        return count;
    }
};
