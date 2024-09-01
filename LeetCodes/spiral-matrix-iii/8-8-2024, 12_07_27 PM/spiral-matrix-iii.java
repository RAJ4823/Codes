// Link: https://leetcode.com/problems/spiral-matrix-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: spiral-matrix-iii
 *  RUNTIME: 4 ms
 *  MEMORY: 45.3 MB
 *  DATE: 8-8-2024, 12:07:27 PM
 *
 */

// Solution:

class Solution {
    public int[][] spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        int[][] mat = new int[rows*cols][2];
        
        int cell = 0, steps = 0, i = rStart, j = cStart;
        mat[0][0] = i;
        mat[0][1] = j;
        cell++;

        while(cell < rows * cols) {
            steps++;
            
            // Left to Right
            for(int k=0; k<steps; k++) {
                j++;
                if(isValidCell(i, j, cell, rows, cols)) {
                    mat[cell][0] = i;
                    mat[cell][1] = j;
                    cell++;
                }
            }

            // Top to bottom
            for(int k=0; k<steps; k++) {
                i++;
                if(isValidCell(i, j, cell, rows, cols)) {
                    mat[cell][0] = i;
                    mat[cell][1] = j;
                    cell++;
                }
            }

            steps++;

            // Right to Left
            for(int k=0; k<steps; k++) {
                j--;
                if(isValidCell(i, j, cell, rows, cols)) {
                    mat[cell][0] = i;
                    mat[cell][1] = j;
                    cell++;
                }
            }

            // Bottom to Top
            for(int k=0; k<steps; k++) {
                i--;
                if(isValidCell(i, j, cell, rows, cols)) {
                    mat[cell][0] = i;
                    mat[cell][1] = j;
                    cell++;
                }
            }
        }

        return mat;
    }

    public boolean isValidCell(int i, int j, int cell, int rows, int cols) {
        return (cell < rows * cols && i < rows && j < cols && i >= 0 && j >= 0);
    }
}
