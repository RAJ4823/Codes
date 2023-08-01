// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-path-in-binary-matrix
 *  RUNTIME: 62 ms
 *  MEMORY: 20.1 MB
 *  DATE: 6-1-2023, 10:27:47 AM
 *
 */

// Solution:

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;

        int n = grid.size();
        queue<pair<pair<int,int>, int>> q; // {{row, col}, dist};
        q.push({{0,0}, 1});

        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int d = q.front().second;
            q.pop();

            if(i == n-1 && j == n-1) return d;
            for(int x=-1; x<=1; x++) {
                for(int y=-1; y<=1; y++) {
                    int row = i + x;
                    int col = j + y;

                    if(row == i && col == j) continue;
                    if(row < 0 || row >= n || col < 0 || col >= n) continue;
                    if(!grid[row][col]) {
                        grid[row][col] = 1;
                        q.push({{row, col}, d + 1});
                    }
                }
            }
        }
        return -1;
    }
};
