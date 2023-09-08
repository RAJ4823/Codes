// Link: https://leetcode.com/problems/n-queens

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: n-queens
 *  RUNTIME: 3 ms
 *  MEMORY: 7 MB
 *  DATE: 8-2-2023, 5:17:45 PM
 *
 */

// Solution:

class Solution {
public:
    bool isValidRow(int row, int col, int n, vector<string> &board) {
        // Check if column had a queen
        for(int i=0; i<row; i++) {
            if(board[i][col] == 'Q')
                return false;
        }

        // Check 45* diagonal line
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }

        // Check  135* diagonal line
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++) {
            if(board[i][j] == 'Q') 
                return false;
        }
        return true;
    }
    void backtrack(int row, int &n, vector<string> &board, vector<vector<string>> &ans) {
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col=0; col<n; col++) {
            if(isValidRow(row, col, n, board)) {
                board[row][col] = 'Q';
                backtrack(row+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board, ans);
        return ans;
    }
};
