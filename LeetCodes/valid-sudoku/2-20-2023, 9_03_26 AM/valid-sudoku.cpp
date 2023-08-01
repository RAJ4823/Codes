// Link: https://leetcode.com/problems/valid-sudoku

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: valid-sudoku
 *  RUNTIME: 20 ms
 *  MEMORY: 17.9 MB
 *  DATE: 2-20-2023, 9:03:26 AM
 *
 */

// Solution:

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][10] = {0};
        int col[9][10] = {0};
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;
                int val = (int)(board[i][j] - '0');
                // cout << val << endl;
                row[i][val]++;
                col[j][val]++;
                if(row[i][val] > 1) return false;
                if(col[j][val] > 1) return false;
            }
        }
        for(int k=0; k<3; k++) {
            for(int l=0; l<3; l++) {
                int box[10] = {0};
                for(int i=k*3; i<k*3+3; i++) {
                    for(int j=l*3; j<l*3+3; j++) {
                        if(board[i][j] == '.') continue;
                        int val = board[i][j] - '0';
                        box[val]++;
                        if(box[val] > 1) return false;
                    }
                }
            }
        }
        return true;
    }
};
