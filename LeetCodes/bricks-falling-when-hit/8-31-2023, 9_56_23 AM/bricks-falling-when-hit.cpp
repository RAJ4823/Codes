// Link: https://leetcode.com/problems/bricks-falling-when-hit

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: bricks-falling-when-hit
 *  RUNTIME: 288 ms
 *  MEMORY: 106.9 MB
 *  DATE: 8-31-2023, 9:56:23 AM
 *
 */

// Solution:

class DisjointSet {
public:
    vector<int> par, size;
    DisjointSet(int n) {
        par.resize(n);
        size.resize(n, 1);
        for(int i=0; i<n; i++) 
            par[i] = i;
    }

    int findPar(int x) {
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    bool merge(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);

        if(px == py) return false;
        if(size[px] > size[py]) {
            par[py] = px;
            size[px] += size[py];
        } else {
            par[px] = py;
            size[py] += size[px];
        }
        return true;
    }

    int getSize() {
        int root = findPar(0);
        return size[root];
    }
};
class Solution {
public:
    int n, m;
    int dirs[5] = {-1, 0, 1, 0, -1};

    void unionAround(int x, int y, DisjointSet &ds, vector<vector<int>>& grid ) {
        int node = x * m + y + 1;
        for(int k=0; k<4; k++) {
            int nx = x + dirs[k];
            int ny = y + dirs[k+1];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1) {
                int next = nx * m + ny + 1;
                ds.merge(node, next);
            }
        }

        if(x == 0) {
            ds.merge(0, node);
        }
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size();
        m = grid[0].size();

        DisjointSet ds(n * m + 1);

        /** Mark cells to hit as 2. */
        for(auto &hit: hits) {
            int x = hit[0], y = hit[1];
            if(grid[x][y] == 1) {
                grid[x][y] = 2;
            }
        }

        /** Union around 1 cells. */
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) { 
                    unionAround(i, j, ds, grid);
                }
            }
        }

        int totalBricks = ds.getSize();
        int h = hits.size();
        vector<int> ans(h);

        for(int i=h-1; i>=0; i--) {
            int x = hits[i][0];
            int y = hits[i][1];
            if(grid[x][y] == 2) {
                grid[x][y] = 1;
                unionAround(x, y, ds, grid);

                int newTotalBricks = ds.getSize();
                ans[i] = max(0, newTotalBricks - totalBricks - 1);
                totalBricks = newTotalBricks;
            }
        }
        return ans;
    }
};
