// Link: https://leetcode.com/problems/di-string-match

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: di-string-match
 *  RUNTIME: 3 ms
 *  MEMORY: 9.3 MB
 *  DATE: 9-16-2023, 3:09:05 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> ans;
        int i=0, j = s.size();
        for(auto &ch: s) {
            if(ch == 'I') {
                ans.push_back(i++);
            } else {
                ans.push_back(j--);
            }
        }
        ans.push_back(i);
        return ans;
    }
};
