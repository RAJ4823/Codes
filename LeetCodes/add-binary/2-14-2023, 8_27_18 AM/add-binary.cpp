// Link: https://leetcode.com/problems/add-binary

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: add-binary
 *  RUNTIME: 3 ms
 *  MEMORY: 7 MB
 *  DATE: 2-14-2023, 8:27:18 AM
 *
 */

// Solution:

class Solution {
public:    
    string addBinary(string a, string b) {
        string s = "";
        
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while(i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        
        return s;
    }
};
