// Link: https://leetcode.com/problems/matrix-diagonal-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: matrix-diagonal-sum
 *  RUNTIME: 15 ms
 *  MEMORY: 11.3 MB
 *  DATE: 5-8-2023, 2:12:38 PM
 *
 */

// Solution:

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int n = mat.size();

        int i=0, j=0;
        while(i < n && j < n) {
            sum += mat[i++][j++];
        }
        i = 0, j = n-1;
        while(i < n && j >=0) {
            sum += mat[i++][j--];
        }
        if(n % 2) sum -= mat[n/2][n/2];
        return sum;
    }
};
