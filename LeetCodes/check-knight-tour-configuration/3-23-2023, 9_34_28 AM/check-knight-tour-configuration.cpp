// Link: https://leetcode.com/problems/check-knight-tour-configuration

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-knight-tour-configuration
 *  RUNTIME: 15 ms
 *  MEMORY: 28.4 MB
 *  DATE: 3-23-2023, 9:34:28 AM
 *
 */

// Solution:

class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int,int>> pos(n*n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }
        
        if(grid[0][0] != 0) return false;
        for(int i=1; i<n*n; i++) {
            int diffx = abs(pos[i-1].first - pos[i].first);
            int diffy = abs(pos[i-1].second - pos[i].second);
            
            if(min(diffx, diffy) == 1 && max(diffx, diffy) == 2) continue;
            else return false;
        }
        
        return true;
    }
};
