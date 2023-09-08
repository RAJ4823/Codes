// Link: https://leetcode.com/problems/pascals-triangle

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: pascals-triangle
 *  RUNTIME: 0 ms
 *  MEMORY: 6.8 MB
 *  DATE: 9-8-2023, 10:06:17 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        
        return ans;
    }
};
