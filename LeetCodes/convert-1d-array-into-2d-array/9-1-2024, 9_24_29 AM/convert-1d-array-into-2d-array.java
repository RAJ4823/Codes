// Link: https://leetcode.com/problems/convert-1d-array-into-2d-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: convert-1d-array-into-2d-array
 *  RUNTIME: 4 ms
 *  MEMORY: 55.4 MB
 *  DATE: 9-1-2024, 9:24:29 AM
 *
 */

// Solution:

class Solution {
    public int[][] construct2DArray(int[] arr, int rows, int cols) {
        if(rows*cols != arr.length) return new int[0][0];

        int[][] mat = new int[rows][cols];
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                mat[i][j] = arr[i * cols + j];
            }
        }
        return mat;
    }
}
