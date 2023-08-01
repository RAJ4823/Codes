// Link: https://leetcode.com/problems/palindrome-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: palindrome-number
 *  RUNTIME: 15 ms
 *  MEMORY: 5.8 MB
 *  DATE: 1-26-2023, 10:48:03 AM
 *
 */

// Solution:

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        string s = "";
        while(x > 0) {
            s += (x%10 + '0');
            x/=10;
        }
        int i = 0, j = s.length() -1;
        while(i < j) {
            if(s[i++] != s[j--])
                return false;
        }
        return true;
    }
};
