// Link: https://leetcode.com/problems/sudoku-solver

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sudoku-solver
 *  RUNTIME: 5 ms
 *  MEMORY: 41 MB
 *  DATE: 7-10-2024, 2:39:23 PM
 *
 */

// Solution:

class Solution {
    public void solveSudoku(char[][] board) {
        solve(0, 0, board);
    }

    public boolean solve(int i, int j, char[][] board) {
        if(i == 9) return true;

        int row = i, col = j + 1;
        if(j + 1 == 9) {
            row++;
            col = 0;
        } 

        if(board[i][j] == '.') {
            for(char num='1'; num <= '9'; num++) {
                if(isSafe(num, i, j, board)) {
                    board[i][j] = num;
                    if(solve(row, col, board)) {
                        return true;
                    } else {
                        board[i][j] = '.';
                    }
                }
            }
        } else {
            return solve(row, col, board);
        }
        return false;
    }

    public boolean isSafe(char num, int row, int col, char[][] board) {
        // check row
        for(int i=0; i<9; i++) {
            if(board[i][col] == num)
                return false;
        }

        // check col
        for(int j=0; j<9; j++) {
            if(board[row][j] == num)
                return false;
        }

        //grid
        int gridRow = (row/3)*3;
        int gridCol = (col/3)*3;
        
        for(int x=gridRow;x<gridRow+3;x++){
            for(int y=gridCol;y<gridCol+3;y++){
                if(board[x][y]==num){
                    return false;
                }
            }
        }
    
        return true;
    }
}
