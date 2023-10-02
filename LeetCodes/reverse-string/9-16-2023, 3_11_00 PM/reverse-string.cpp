// Link: https://leetcode.com/problems/reverse-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reverse-string
 *  RUNTIME: 19 ms
 *  MEMORY: 23.5 MB
 *  DATE: 9-16-2023, 3:11:00 PM
 *
 */

// Solution:

class Solution {
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            swap(s[i++], s[j--]);
        }
    }
};
