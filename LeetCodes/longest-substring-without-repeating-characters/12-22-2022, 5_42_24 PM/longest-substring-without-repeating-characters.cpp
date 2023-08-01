// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-substring-without-repeating-characters
 *  RUNTIME: 41 ms
 *  MEMORY: 13.6 MB
 *  DATE: 12-22-2022, 5:42:24 PM
 *
 */

// Solution:

#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0, j=0, maxi = 0;
        set<char> chars;
        while(j < n) {
            if(chars.find(s[j]) != chars.end()) {
                maxi = max(maxi, (int)chars.size());
                while(s[i] != s[j]) chars.erase(s[i++]);
                chars.erase(s[i++]);
            }   
            chars.insert(s[j++]);
        }
        return max(maxi, (int)chars.size());
    }
};
