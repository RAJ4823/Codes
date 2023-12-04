// Link: https://leetcode.com/problems/largest-3-same-digit-number-in-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: largest-3-same-digit-number-in-string
 *  RUNTIME: 3 ms
 *  MEMORY: 6.8 MB
 *  DATE: 12-4-2023, 7:03:22 PM
 *
 */

// Solution:

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "0", curr = "";
        for(int i=0; i<num.size(); i++) {
            curr += num[i];
            if(curr.size() == 3) {
                if(curr[0] == curr[1] && curr[1] == curr[2]) {
                    ans = (stoi(ans) > stoi(curr)) ? ans : curr;
                }
                curr = curr.substr(1);
            }
        }
        return (ans == "0" ? "" : ans);
    }
};
