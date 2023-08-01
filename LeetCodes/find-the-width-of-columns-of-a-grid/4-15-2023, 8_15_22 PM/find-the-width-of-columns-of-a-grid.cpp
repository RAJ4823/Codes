// Link: https://leetcode.com/problems/find-the-width-of-columns-of-a-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-width-of-columns-of-a-grid
 *  RUNTIME: 20 ms
 *  MEMORY: 10.2 MB
 *  DATE: 4-15-2023, 8:15:22 PM
 *
 */

// Solution:

class Solution {
public:

    vector<int> findColumnWidth(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
                vector<int> ans(m);
        for(int i=0; i<m; i++) {
            int mini = INT_MAX, maxi = INT_MIN;
            for(int j=0; j<n; j++) {
                mini = min(mini, grid[j][i]);
                maxi = max(maxi, grid[j][i]);
            }
            auto num1 = to_string(mini);
            auto num2 = to_string(maxi);
            ans[i] = max(num1.size(), num2.size());
        }
        return ans;
    }
};
