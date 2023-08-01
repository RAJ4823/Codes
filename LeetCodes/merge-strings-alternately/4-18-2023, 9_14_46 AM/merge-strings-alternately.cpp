// Link: https://leetcode.com/problems/merge-strings-alternately

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: merge-strings-alternately
 *  RUNTIME: 0 ms
 *  MEMORY: 6.4 MB
 *  DATE: 4-18-2023, 9:14:46 AM
 *
 */

// Solution:

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int n=word1.size(), m = word2.size();
        int i=0, j=0;
        while(i < n && j < m) {
            ans += word1[i++];
            ans += word2[j++];
        }
        while(i < n) ans += word1[i++];
        while(j < m) ans += word2[j++];
        return ans;
    }
};
