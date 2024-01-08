// Link: https://leetcode.com/problems/count-and-say

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-and-say
 *  RUNTIME: 0 ms
 *  MEMORY: 7.1 MB
 *  DATE: 12-8-2023, 7:36:26 PM
 *
 */

// Solution:

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string prev = countAndSay(n - 1);
        string res = "";
        int pos = 0;

        while(pos < prev.size()) {
            int count = 0;
            while(pos + count < prev.size() && prev[pos] == prev[pos+count]) {
                count++;
            }

            res += ('0' + count);
            res += prev[pos];
            pos = pos + count;
        }

        return res;
    }
};
