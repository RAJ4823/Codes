// Link: https://leetcode.com/problems/palindrome-partitioning

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: palindrome-partitioning
 *  RUNTIME: 653 ms
 *  MEMORY: 334.2 MB
 *  DATE: 1-22-2023, 10:09:50 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string str) {
        string rev = str;
        reverse(str.begin(), str.end());
        return rev == str;
    }

    bool check(vector<string> &v, string &s) {
        int i = 0;
        for(auto &str: v) {
            for(auto &ch: str) {
                if(ch == s[i]) i++;
            }
        }
        return i == s.length();
    }
    void find(int start, int end, int n, string &s, vector<string> v) {
       if(end == n) {
           if(check(v, s)) ans.push_back(v);
           return;
       }

       string str = "";
       for(int i = start; i <= end; i++) {
           str += s[i];
       }

       if(isPalindrome(str)) {
           v.push_back(str);
           find(end+1, end+1, n, s, v);
           v.pop_back();
       }
       find(start, end+1, n, s, v);
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> v;
        find(0, 0, n, s, v);
        return ans;
    }
};
