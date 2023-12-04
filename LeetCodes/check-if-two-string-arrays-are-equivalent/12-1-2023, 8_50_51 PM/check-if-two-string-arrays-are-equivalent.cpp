// Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-two-string-arrays-are-equivalent
 *  RUNTIME: 4 ms
 *  MEMORY: 11.9 MB
 *  DATE: 12-1-2023, 8:50:51 PM
 *
 */

// Solution:

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0, j = 0; // word pointers
        int m = 0, n = 0; // char pointers
        
        while (i < word1.size() and j < word2.size()) {            
            if (word1[i][m++] != word2[j][n++])
                return false;
            
            if (m >= word1[i].size())
                i++, m = 0;
            
            if (n >= word2[j].size())
                j++, n = 0;
        }
        
        return i == word1.size() and j == word2.size();
    }
};
