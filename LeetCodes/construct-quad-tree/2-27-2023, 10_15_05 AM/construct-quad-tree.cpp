// Link: https://leetcode.com/problems/construct-quad-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: construct-quad-tree
 *  RUNTIME: 16 ms
 *  MEMORY: 16.1 MB
 *  DATE: 2-27-2023, 10:15:05 AM
 *
 */

// Solution:

class Solution {
public:
    bool isLeafNode(int row_start, int row_end, int col_start, int col_end, vector<vector<int>>& grid) {
        int value = grid[row_start][col_start];
        for(int i=row_start; i<=row_end; i++) {
            for(int j=col_start; j<=col_end; j++) {
                if(grid[i][j] != value) return false;
            }
        }
        return true;
    }
    Node* quadTree(int row_start, int row_end, int col_start, int col_end, vector<vector<int>>& grid) {
        if(row_start > row_end || col_start > col_end) 
            return NULL;

        if(isLeafNode(row_start, row_end, col_start, col_end, grid))
            return new Node(grid[row_start][col_start], true);

        int row_mid = (row_start + row_end) / 2;
        int col_mid = (col_start + col_end) / 2;

        Node* TL = quadTree(row_start, row_mid, col_start, col_mid, grid);// TopLeftNode
        Node* TR = quadTree(row_start, row_mid, col_mid+1, col_end, grid);// TopRightNode    
        Node* BL = quadTree(row_mid+1, row_end, col_start, col_mid, grid);// BottomLeftNode
        Node* BR = quadTree(row_mid+1, row_end, col_mid+1, col_end, grid);// BottomRightNode

        return new Node(false, false, TL, TR, BL, BR);
    }
    Node* construct(vector<vector<int>>& grid) {
       int n = grid.size();
       return quadTree(0, n-1, 0, n-1, grid); 
    }
};
