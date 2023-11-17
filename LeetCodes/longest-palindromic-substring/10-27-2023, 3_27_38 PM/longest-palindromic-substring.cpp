// Link: https://leetcode.com/problems/longest-palindromic-substring

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-palindromic-substring
 *  RUNTIME: 7 ms
 *  MEMORY: 7.3 MB
 *  DATE: 10-27-2023, 3:27:38 PM
 *
 */

// Solution:

class Solution {
public:

    int getLength(pair<int,int> &range) {
        return (range.second - range.first + 1);
    }

    pair<int,int> expandAroundCenter(string &s, int n, int i, int j) {
        if(j >= n || s[i] != s[j]) return {0, 0};
        while(i >= 0 && j < n && s[i] == s[j]) {
            i--;
            j++;
        }
        return {i+1, j-1};
    }

    string longestPalindrome(string s) {
        if(s.empty()) return "";

        pair<int,int> maxRange = {0,0}, currRange = {-1,-1};
        int n = s.length();
        for(int i=0; i<n; i++) {
            // Check for odd-length palindrome centered at i
            currRange = expandAroundCenter(s, n, i, i);
            if(getLength(currRange) > getLength(maxRange)) {
                maxRange = currRange;
            }

            // Check for even-length palindrome centered at i and i+1
            currRange = expandAroundCenter(s, n, i, i+1);
            if(getLength(currRange) > getLength(maxRange)) {
                maxRange = currRange;
            }
        }

        string ans = s.substr(maxRange.first, getLength(maxRange));
        return ans;
    }
};
