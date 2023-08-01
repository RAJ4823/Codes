// Link: https://leetcode.com/problems/battleships-in-a-board

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: battleships-in-a-board
 *  RUNTIME: 6 ms
 *  MEMORY: 8.2 MB
 *  DATE: 1-28-2023, 12:01:52 PM
 *
 */

// Solution:

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]=='X' && (i==0 || board[i-1][j]!='X') && 
                (j==0 || board[i][j-1]!='X')) 
                count++;
            }
        }
        return count;
    }
};
