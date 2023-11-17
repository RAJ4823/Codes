// Link: https://leetcode.com/problems/consecutive-characters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: consecutive-characters
 *  RUNTIME: 6 ms
 *  MEMORY: 7.1 MB
 *  DATE: 11-9-2023, 6:40:15 PM
 *
 */

// Solution:

class Solution {
public:
    int maxPower(string s) {
        long long curr = '0', count = 0, maxi = 0;
        for(auto &ch: s) {
            if(curr == ch) {
                count++;
            } else {
                maxi = max(maxi, count);
                curr = ch;
                count = 1;
            }
        }
        return max(maxi, count);
    }
};
