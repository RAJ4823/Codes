// Link: https://leetcode.com/problems/excel-sheet-column-title

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: excel-sheet-column-title
 *  RUNTIME: 0 ms
 *  MEMORY: 5.9 MB
 *  DATE: 8-2-2023, 4:02:37 PM
 *
 */

// Solution:

class Solution {
public:
    string convertToTitle(int n) {
        string str;
        while(n > 0) {
            int rem = n%26;
            if(rem == 0) {
                str += 'Z';
                n--;
            } else {
                str += (char)(rem + 64);
            }
            n /= 26;
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
