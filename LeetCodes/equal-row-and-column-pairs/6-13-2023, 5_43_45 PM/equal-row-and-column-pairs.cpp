// Link: https://leetcode.com/problems/equal-row-and-column-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: equal-row-and-column-pairs
 *  RUNTIME: 100 ms
 *  MEMORY: 32.7 MB
 *  DATE: 6-13-2023, 5:43:45 PM
 *
 */

// Solution:


class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> mp;
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        for (int i=0; i<n; i++) {
            mp[grid[i]]++;
        }
        for (int j=0; j<m; j++) {
            vector<int> temp;
            for (int i=0; i<n; i++) {
                temp.emplace_back(grid[i][j]);
            }
            ans += mp[temp];
        }
        return ans;
    }
};
