// Link: https://leetcode.com/problems/largest-substring-between-two-equal-characters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: largest-substring-between-two-equal-characters
 *  RUNTIME: 2 ms
 *  MEMORY: 6.7 MB
 *  DATE: 12-31-2023, 3:17:21 PM
 *
 */

// Solution:

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int> prev(26, -1);
        int ans = -1; 

        for(int i=0; i<s.size(); i++) {
            int ch = s[i] - 'a';
            if(prev[ch] == -1) {
                prev[ch] = i;
            } else {
                ans = max(ans, i - prev[ch] - 1);
            }
        }

        return ans;
    }
};
