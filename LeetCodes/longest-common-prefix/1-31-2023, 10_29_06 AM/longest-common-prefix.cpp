// Link: https://leetcode.com/problems/longest-common-prefix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-common-prefix
 *  RUNTIME: 0 ms
 *  MEMORY: 9.3 MB
 *  DATE: 1-31-2023, 10:29:06 AM
 *
 */

// Solution:

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int n = strs.size();
        if(n == 1) return strs[0];
        int m = INT_MAX;
        for(int i=1; i<n; i++) {
            m = min(m, (int)strs[i].size());
        }

        for(int j=0; j<m; j++) {
            for(int i=1; i<n; i++) {
                if(strs[i-1][j] != strs[i][j]) {
                    return prefix;
                }
            }
            prefix += strs[0][j];
        }
        return prefix;
    }
};
