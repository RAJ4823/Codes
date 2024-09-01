// Link: https://leetcode.com/problems/design-neighbor-sum-service

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: design-neighbor-sum-service
 *  RUNTIME: 18 ms
 *  MEMORY: 45.8 MB
 *  DATE: 8-7-2024, 11:40:10 AM
 *
 */

// Solution:

class neighborSum {
    int[][] g;
    Map<Integer, int[]> mp = new HashMap<>();
    int n, m;
    
    public int getVal(int i, int j) {
        if(i < 0 || j < 0 || i >= n || j >= m)
                return 0;
        return g[i][j];
    }
    
    public neighborSum(int[][] grid) {
        n = grid.length;
        m = grid[0].length;
        g = grid;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                mp.put(grid[i][j], new int[]{i, j});
            }
        }
    }
    
    public int adjacentSum(int value) {
        int[] cell = mp.get(value);
        int i = cell[0];
        int j = cell[1];
        return getVal(i-1,j) + getVal(i+1,j) + getVal(i,j-1) + getVal(i,j+1);
    }
    
    public int diagonalSum(int value) {
        int[] cell = mp.get(value);
        int i = cell[0];
        int j = cell[1];
        return getVal(i-1,j-1) + getVal(i+1,j+1) + getVal(i+1,j-1) + getVal(i-1,j+1);
    }
}

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum obj = new neighborSum(grid);
 * int param_1 = obj.adjacentSum(value);
 * int param_2 = obj.diagonalSum(value);
 */
