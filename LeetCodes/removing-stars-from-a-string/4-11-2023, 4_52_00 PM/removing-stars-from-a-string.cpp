// Link: https://leetcode.com/problems/removing-stars-from-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: removing-stars-from-a-string
 *  RUNTIME: 88 ms
 *  MEMORY: 27.7 MB
 *  DATE: 4-11-2023, 4:52:00 PM
 *
 */

// Solution:

class Solution {
public:
    string removeStars(string s) {
        vector<char> st;
        string ans = "";

        for(auto &ch: s) {
            if(ch == '*') st.pop_back();
            else st.push_back(ch);
        }
        for(auto &ch: st) {
            ans += ch;
        }
        return ans;
    }
};
