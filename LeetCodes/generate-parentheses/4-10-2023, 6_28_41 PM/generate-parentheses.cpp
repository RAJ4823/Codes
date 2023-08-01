// Link: https://leetcode.com/problems/generate-parentheses

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: generate-parentheses
 *  RUNTIME: 4 ms
 *  MEMORY: 14 MB
 *  DATE: 4-10-2023, 6:28:41 PM
 *
 */

// Solution:

class Solution {
public:
    vector<string> ans;
    void find(string str, int open, int close) {
        if(close == 0) {
            ans.push_back(str);
            return;
        }
        
        if(open > 0)        find(str + '(', open - 1, close);
        if(close > open)   find(str + ')', open, close - 1);
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        find(str, n, n);
        return ans;
    }
};
