// Link: https://leetcode.com/problems/magic-squares-in-grid

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: magic-squares-in-grid
 *  RUNTIME: 0 ms
 *  MEMORY: 41.1 MB
 *  DATE: 8-9-2024, 2:50:38 PM
 *
 */

// Solution:

class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int ans = 0;
        int n = grid.length;
        int m = grid[0].length;
        for(int row=0; row<=n-3; row++) {
            for(int col=0; col<=m-3; col++) {
                ans += isValid(row, col, grid);
            }
        }
        return ans;
    }

    int isValid(int row, int col, int[][] grid) {
        int[] rowSum = new int[3];
        int[] colSum = new int[3];
        int[] nums = new int[10];

        for(int i=row; i<row+3; i++) {
            for(int j=col; j<col+3; j++) {
                int cell = grid[i][j];
                rowSum[i%3] += cell;
                colSum[j%3] += cell;

                if(cell > 0 && cell < 10 && nums[cell] == 0) {
                    nums[cell] = 1;
                } else {
                    return 0;
                }
            }
        }

        int dig1 = grid[row][col] + grid[row+1][col+1] + grid[row+2][col+2];
        int dig2 = grid[row+2][col] + grid[row+1][col+1] + grid[row][col+2];
        
        if(dig1 != dig2) return 0;

        for(int i=0; i<2; i++) {
            if(rowSum[i] != rowSum[i+1]) return 0;
            if(colSum[i] != colSum[i+1]) return 0;
        }

        return 1;
    }
}
