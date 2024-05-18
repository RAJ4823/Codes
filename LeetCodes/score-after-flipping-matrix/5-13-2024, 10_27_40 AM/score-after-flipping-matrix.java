// Link: https://leetcode.com/problems/score-after-flipping-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: score-after-flipping-matrix
 *  RUNTIME: 0 ms
 *  MEMORY: 41.7 MB
 *  DATE: 5-13-2024, 10:27:40 AM
 *
 */

// Solution:

class Solution {
    public int matrixScore(int[][] grid) {
        // Make 1st element of each row '1'
        for(int row=0; row<grid.length; row++) {
            if(grid[row][0] == 0) {
                flipRow(row, grid);
            }
        }

        // Maximize 1's count in each column
        for(int col=1; col<grid[0].length; col++) {
            int countOne = 0;
            for(int row=0; row<grid.length; row++) {
                countOne += grid[row][col];
            }
            if(countOne * 2 < grid.length) {
                flipCol(col, grid);
            }
        }

        return countScore(grid);
    }

    public void flipRow(int row, int[][] grid) {
        for(int col=0; col<grid[row].length; col++) {
            grid[row][col] = 1 - grid[row][col];
        }
    }

    public void flipCol(int col, int[][] grid) {
        for(int row=0; row<grid.length; row++) {
            grid[row][col] = 1 - grid[row][col];
        }
    }

    public int countScore(int[][] grid) {
        int score = 0;
        for(int row=0; row<grid.length; row++) {
            int res = 0;
            for(int col=0; col<grid[row].length; col++) {
                res = res * 2 + grid[row][col];
            }
            score += res;
        }
        return score;
    }
}
