// Link: https://leetcode.com/problems/shortest-bridge

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-bridge
 *  RUNTIME: 740 ms
 *  MEMORY: 23.7 MB
 *  DATE: 5-21-2023, 6:10:53 PM
 *
 */

// Solution:

class Solution {
public:
    vector<pair<int,int>> first,second;
    int n;
    
    void dfs(int i,int j, int no, vector<vector<int>>& grid)
    {
        if(i<0||j<0||i>=n||j>=n||grid[i][j]!=1) return;
        grid[i][j]=no;

        if(no==2) first.push_back({i,j});
        else second.push_back({i,j});

        dfs(i+1,j,no,grid);
        dfs(i-1,j,no,grid);
        dfs(i,j+1,no,grid);
        dfs(i,j-1,no,grid);
    }
    
    
    int shortestBridge(vector<vector<int>>& grid) {
        int mark=2;
        n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) {
                    dfs(i,j,mark,grid);
                    mark++;
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<first.size();i++) {
            for(int j=0;j<second.size();j++) {
                int diff1 = abs(first[i].first-second[j].first);
                int diff2 = abs(first[i].second-second[j].second);
                int dist = diff1 + diff2 - 1;
                ans = min(dist,ans);
            }
        }
        return ans;
    }
};
