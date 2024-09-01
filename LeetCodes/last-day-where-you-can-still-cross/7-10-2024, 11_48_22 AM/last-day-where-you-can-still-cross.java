// Link: https://leetcode.com/problems/last-day-where-you-can-still-cross

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: last-day-where-you-can-still-cross
 *  RUNTIME: 23 ms
 *  MEMORY: 56.9 MB
 *  DATE: 7-10-2024, 11:48:22 AM
 *
 */

// Solution:

public class DisjointSet {
    int[] size, par;

    DisjointSet(int n) {
        size = new int[n];
        par = new int[n];
        for(int i=0; i<n; i++) {
            size[i] = 1;
            par[i] = i;
        }
    }

    public int findPar(int x) {
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    public void merge(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);

        if(px == py) return;
        
        if(size[px] < size[py]) {
            par[px] = py;
            size[py] += size[px];
        } else {
            par[py] = px;
            size[px] += size[py];
        }
    }

    public boolean isConnected(int x, int y) {
        return (findPar(x) == findPar(y));
    }
}

class Solution {
    public int latestDayToCross(int row, int col, int[][] cells) {
        int[][] grid = new int[row][col];
        
        // Mark the cells as flooded (1) based on the input cells array
        for(int[] cell: cells) {
            grid[cell[0] - 1][cell[1] - 1] = 1;
        }

        int[] dirs = new int[]{-1, 0, 1, 0, -1}; // Directions array for easy traversal (up, right, down, left)
        int totalCells = row * col; // Total number of cells in the grid
        int rowStart = totalCells, rowEnd = totalCells + 1; // Virtual cells representing the top and bottom rows
        
        // Create a disjoint-set data structure with totalCells + 2 elements (including virtual cells)
        DisjointSet ds = new DisjointSet(totalCells + 2);

        // Iterate over the grid and establish initial connections between adjacent land cells
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                for(int k=0; k<4; k++) {
                    int ni = i + dirs[k];
                    int nj = j + dirs[k+1];

                    if(ni >=0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 0) {
                        int nodeVal = i * col + j;
                        int nextVal = ni* col + nj;

                        // Merge the current node and the next node (if they are both land cells)
                        ds.merge(nodeVal, nextVal);
                    }
                }
            }
        }

        // Iterate over the flooded cells in reverse order
        for(int c=totalCells-1; c>=0; c--) {
            int i = cells[c][0] - 1;
            int j = cells[c][1] - 1;
            int currNodeVal = i * col + j;

            grid[i][j] = 0; // Mark the cell as land (unflooded)

            for(int k=0; k<4; k++) {
                int ni = i + dirs[k];
                int nj = j + dirs[k+1];

                if(ni >=0 && ni < row && nj >= 0 && nj < col && grid[ni][nj] == 0) {
                    int nodeVal = i * col + j;
                    int nextVal = ni* col + nj;

                    // Merge the current node and the next node (if they are both land cells)
                    ds.merge(nodeVal, nextVal);
                }
            }

            // Merge the current node with the rowStart virtual node if it is in the top row
            if(i == 0)      
                ds.merge(rowStart, currNodeVal); 
            
            // Merge the current node with the rowEnd virtual node if it is in the bottom row
            if(i == row-1)  
                ds.merge(rowEnd, currNodeVal); 

            // Check if the rowStart virtual node and the rowEnd virtual node are connected,
            // indicating a path from top to bottom exists, then return 'c' (current day)            
            if(ds.isConnected(rowStart, rowEnd))  
                return c; 
        }

        // No path from top to bottom exists, so return '0' (first Day)
        return 0;
    }
}
