// Link: https://leetcode.com/problems/remove-trailing-zeros-from-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-trailing-zeros-from-a-string
 *  RUNTIME: 9 ms
 *  MEMORY: 9.4 MB
 *  DATE: 5-30-2023, 9:22:39 AM
 *
 */

// Solution:

class Solution {
public:
    string removeTrailingZeros(string num) {
        string str = "";
        int n = num.size();
        int i = n-1;
        while(num[i] == '0') i--; 
        for(int j=0; j<=i; j++) {
            str += num[j];
        }
        return str;
    }
};
