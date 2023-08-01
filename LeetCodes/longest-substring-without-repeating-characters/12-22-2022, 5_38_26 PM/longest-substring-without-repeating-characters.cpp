// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-substring-without-repeating-characters
 *  RUNTIME: 35 ms
 *  MEMORY: 13.5 MB
 *  DATE: 12-22-2022, 5:38:26 PM
 *
 */

// Solution:

#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0, j=0;
        int maxi = 0;

        set<char> st;
        while(j < n) {
            if(st.find(s[j]) != st.end()) {
                maxi = max(maxi, (int)st.size());
                while(s[i] != s[j] && i < j) {
                    st.erase(s[i]);
                    i++;
                }
                st.erase(s[i]);
                i++;
            }   
            st.insert(s[j]);
            j++;
        }
        maxi = max(maxi, (int)st.size());
        return maxi;
    }
};
