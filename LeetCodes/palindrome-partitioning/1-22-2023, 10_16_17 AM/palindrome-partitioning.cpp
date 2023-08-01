// Link: https://leetcode.com/problems/palindrome-partitioning

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: palindrome-partitioning
 *  RUNTIME: 130 ms
 *  MEMORY: 75.7 MB
 *  DATE: 1-22-2023, 10:16:17 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &str, int i, int j) {
        while (i < j) {
            if (str[i++] != str[j--]) 
                return false;
        }
        return true;
    }

    void find(int start, int n, string &s, vector<string> &v) {
        if (start == n) {
            ans.push_back(v);
            return;
        } 

        string str = "";
        for (int i = start; i < n; i++) {
            str += s[i];
            if (isPalindrome(s, start, i)) {
                v.push_back(str);
                find(i + 1, n, s, v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> v;
        find(0, n, s, v);
        return ans;
    }
};
