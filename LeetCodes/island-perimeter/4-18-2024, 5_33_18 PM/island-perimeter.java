// Link: https://leetcode.com/problems/island-perimeter

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: island-perimeter
 *  RUNTIME: 5 ms
 *  MEMORY: 45.7 MB
 *  DATE: 4-18-2024, 5:33:18 PM
 *
 */

// Solution:

class Solution {
    public int islandPerimeter(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        int[] dir = {-1, 0, 1, 0, -1};
        int count = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    for(int k=0; k<4; k++) {
                        int x = i + dir[k];
                        int y = j + dir[k+1];
                        if(x >= n || x < 0 || y >= m || y < 0 || grid[x][y] == 0) {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
}
