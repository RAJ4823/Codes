// Link: https://leetcode.com/problems/reverse-integer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-integer
 *  RUNTIME: 3 ms
 *  MEMORY: 6.1 MB
 *  DATE: 1-15-2023, 7:00:23 PM
 *
 */

// Solution:

class Solution {
public:
    int reverse(int x) {
        int num = 0;
        int maxi = INT_MAX/10;
        int mini = INT_MIN/10;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (num > maxi || (num == maxi && pop > 7)) return 0;
            if (num < mini || (num == mini && pop < -8)) return 0;
            num = num * 10 + pop;
        }
        return num;
    }
};
