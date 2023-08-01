// Link: https://leetcode.com/problems/spiral-matrix-iii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: spiral-matrix-iii
 *  RUNTIME: 401 ms
 *  MEMORY: 17.8 MB
 *  DATE: 5-9-2023, 4:37:43 PM
 *
 */

// Solution:

class Solution {
public:
    int n, m;
    vector<vector<int>> seq;
    set<pair<int,int>> s;

    bool valid(int row, int col) {
        if(s.find({row,col}) != s.end())
            return false;
        if(row >= 0 && row < n && col >= 0 && col < m) {
            s.insert({row, col});
            return true;
        }
        return false;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        n = rows;
        m = cols;

        int row_start = rStart, row_end = rStart+1;
        int col_start = cStart, col_end = cStart+1;
        int size = 0;
        

        while(size < rows*cols) {
            // Phase:1 (Left to Right)
            for(int i = col_start; i <= col_end && size < rows*cols; i++) {
                if(valid(row_start, i)) {
                    seq.push_back({row_start, i});
                    size++;
                }
                cout << " (" << row_start << ',' << i << ")";
            }
            // Phase:2 (Top to Bottom)
            for(int i = row_start; i <= row_end && size < rows*cols; i++) {
                if(valid(i, col_end)) {
                    seq.push_back({i, col_end});
                    size++;
                }
                cout << " (" << i << ',' << col_end << ")";
            }
            row_start--;
            col_start--;

            // Phase:3 (Right to Left)
            for(int i = col_end; i >= col_start && size < rows*cols; i--) {
                if(valid(row_end, i)) {
                    seq.push_back({row_end, i});
                    size++;
                }
                cout << " (" << row_end << ',' << i << ")";
            }
            // Phase:4 (Bottom to Top)
            for(int i = row_end; i >= row_start && size < rows*cols; i--) {
                if(valid(i, col_start)) {
                    seq.push_back({i, col_start});
                    size++;
                }
                cout << " (" << i << ',' << col_start << ")";
            }
            cout << endl;

            row_end++;
            col_end++;
        }
        return seq;
    }
};
