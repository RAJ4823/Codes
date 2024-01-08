// Link: https://leetcode.com/problems/calculate-money-in-leetcode-bank

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: calculate-money-in-leetcode-bank
 *  RUNTIME: 0 ms
 *  MEMORY: 6.2 MB
 *  DATE: 12-6-2023, 9:46:29 PM
 *
 */

// Solution:

class Solution {
public:
    int totalMoney(int n) {
        int term = n/7;
        int first = 28; //First term for AP
        int last = first + (term - 1) * 7; //Nth term For AP
        int result = term * (first + last) / 2;  //AP Sum 

        if(n % 7) {
            int extraMoney = term + 1;
            for(int i = 0; i < (n % 7); i++) {
                result += extraMoney;
                extraMoney++;
            }
        }
        return result;
    }
};
