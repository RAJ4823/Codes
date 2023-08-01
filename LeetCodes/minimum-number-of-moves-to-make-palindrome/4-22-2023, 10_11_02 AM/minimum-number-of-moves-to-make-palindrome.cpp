// Link: https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-moves-to-make-palindrome
 *  RUNTIME: 21 ms
 *  MEMORY: 7 MB
 *  DATE: 4-22-2023, 10:11:02 AM
 *
 */

// Solution:

class Solution {
public:
    int getIndex(string &s, int l, int i) {
        while(i > l) {
            if(s[i] == s[l]) 
                return i;
            i--;
        }
        return i;
    }
    int find(string s, int l, int r) {
        int steps = 0;
        while(l < r) {
            if(s[l] != s[r]) {
                int i = getIndex(s, l, r);
                if(i == l) {
                    swap(s[i], s[i+1]);
                    steps++;
                } else {
                    while(i < r) {
                        swap(s[i], s[i+1]);
                        steps++;
                        i++;
                    }
                    l++;
                    r--;
                }
            } else {
                l++;
                r--;
            }
        }
        return steps;
    }
    int minMovesToMakePalindrome(string s) {
        int n = s.length();
        return find(s, 0, n-1);
    }
};
