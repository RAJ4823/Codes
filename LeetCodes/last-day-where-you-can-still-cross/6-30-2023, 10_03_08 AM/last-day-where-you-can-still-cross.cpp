// Link: https://leetcode.com/problems/last-day-where-you-can-still-cross

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: last-day-where-you-can-still-cross
 *  RUNTIME: 394 ms
 *  MEMORY: 107.8 MB
 *  DATE: 6-30-2023, 10:03:08 AM
 *
 */

// Solution:

class DisjointSet {
private:
    vector<int> size, par;
public:
    DisjointSet(int n) {
        size.resize(n, 1);
        par.resize(n);
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

        if(px == py) {
            return true;
        }

        if(size[px] < size[py]) {
            par[px] = py;
            size[py] += size[px];
        } else {
            par[py] = px;
            size[px] += size[py];
        }
        return false;
    }

    bool connected(int x, int y) {
        if(findPar(x) == findPar(y))
            return true;
        return false;
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<vector<int>> grid(row, vector<int> (col, 0));

        for(auto &x: cells) {
            int i = x[0] - 1;
            int j = x[1] - 1;
            grid[i][j] = 1;
        }   
        
        int dirs[5] = {-1, 0, 1, 0, -1};
        int totalCells = row*col;
        int rowStart = totalCells;
        int rowEnd = totalCells + 1;
        DisjointSet ds(totalCells + 2);

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                for(int k=0; k<4; k++) {
                    int ni = i + dirs[k];
                    int nj = j + dirs[k+1];
                    if(ni < 0 || ni >= row || nj < 0 || nj >= col || grid[ni][nj] == 1)
                        continue;
                    
                    int nodeVal = i*col + j;
                    int nextVal = ni*col + nj;
                    ds.merge(nodeVal, nextVal);
                }
            }
        }

        for(int c=totalCells-1; c>=0; c--) {
            int i = cells[c][0] - 1;
            int j = cells[c][1] - 1;
            int nodeVal = i*col + j;
            grid[i][j] = 0;

            for(int k=0; k<4; k++) {
                int ni = i + dirs[k];
                int nj = j + dirs[k+1];
                if(ni < 0 || ni >= row || nj < 0 || nj >= col || grid[ni][nj] == 1)
                    continue;
                
                int nextVal = ni*col + nj;
                ds.merge(nodeVal, nextVal);
            }
            if(i == 0)      ds.merge(rowStart, nodeVal);
            if(i == row-1)  ds.merge(rowEnd, nodeVal);
            if(ds.connected(rowStart, rowEnd)) 
                return c;
        }
        return 0;
    }
};
