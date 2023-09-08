// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: letter-combinations-of-a-phone-number
 *  RUNTIME: 0 ms
 *  MEMORY: 6.3 MB
 *  DATE: 8-3-2023, 9:43:06 AM
 *
 */

// Solution:

class Solution {
public:
    string letters[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void find(int i, int &n, string str, string &digits, vector<string> &ans) {
        if(i == n) {
            ans.push_back(str);
            return;
        }
        
        int index = (digits[i] - '0');
        for(int j=0; j<letters[index].size(); j++) {
            find(i+1, n, str + letters[index][j], digits, ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n == 0) return {};
        vector<string> ans;
        string str;
        find(0, n, str, digits, ans);
        return ans;
    }
};
