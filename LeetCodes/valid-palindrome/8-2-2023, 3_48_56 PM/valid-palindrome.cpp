// Link: https://leetcode.com/problems/valid-palindrome

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: valid-palindrome
 *  RUNTIME: 8 ms
 *  MEMORY: 7.8 MB
 *  DATE: 8-2-2023, 3:48:56 PM
 *
 */

// Solution:

class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(auto &ch: s) {
            if(ch >= 'a' && ch <= 'z') str += ch;
            else if(ch >= 'A' && ch <= 'Z') str += (char)(ch + 32);
            else if(ch >= '0' && ch <= '9') str += ch;
        }
        string n = str;
        reverse(str.begin(), str.end());
        return (str == n);
    }
};
