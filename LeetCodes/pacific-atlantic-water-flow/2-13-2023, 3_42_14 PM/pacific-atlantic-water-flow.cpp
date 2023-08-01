// Link: https://leetcode.com/problems/pacific-atlantic-water-flow

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: pacific-atlantic-water-flow
 *  RUNTIME: 46 ms
 *  MEMORY: 18.2 MB
 *  DATE: 2-13-2023, 3:42:14 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        int dirs[5] = {-1,0,1,0,-1};


        vector<vector<bool>> pacific(n, vector<bool> (m, false));
        vector<vector<bool>> antlantic(n, vector<bool> (m, false));
        queue<pair<int,int>> q1, q2;

        for(int i=0; i<n; i++) {
            q1.push({i, 0});
            q2.push({i, m-1});
            pacific[i][0] = true;
            antlantic[i][m-1] = true;
        } 
        for(int j=0; j<m; j++) {
            q1.push({0, j});
            q2.push({n-1, j});
            pacific[0][j] = true;
            antlantic[n-1][j] = true;
        }

        while(!q1.empty()) {
            int row = q1.front().first;
            int col = q1.front().second;
            q1.pop();

            for(int k=0; k<4; k++) {
                int x = row + dirs[k];
                int y = col + dirs[k+1];

                if(x < 0 || y < 0 || x >=n || y >= m) continue;
                if(!pacific[x][y] && heights[x][y] >= heights[row][col]) {
                    q1.push({x, y});
                    pacific[x][y] = true;
                }
            }
        }

         while(!q2.empty()) {
            int row = q2.front().first;
            int col = q2.front().second;
            q2.pop();

            for(int k=0; k<4; k++) {
                int x = row + dirs[k];
                int y = col + dirs[k+1];

                if(x < 0 || y < 0 || x >=n || y >= m) continue;
                if(!antlantic[x][y] && heights[x][y] >= heights[row][col]) {
                    q2.push({x, y});
                    antlantic[x][y] = true;
                }
            }
        }

        vector<vector<int>> ans;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(pacific[i][j] && antlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
