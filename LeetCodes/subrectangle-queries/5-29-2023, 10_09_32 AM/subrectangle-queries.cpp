// Link: https://leetcode.com/problems/subrectangle-queries

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: subrectangle-queries
 *  RUNTIME: 49 ms
 *  MEMORY: 18.7 MB
 *  DATE: 5-29-2023, 10:09:32 AM
 *
 */

// Solution:

class SubrectangleQueries {
public:
    vector<vector<int>> rect;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        int rows = rectangle.size();
        int cols = rectangle[0].size();
        rect.resize(rows, vector<int> (cols));

        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                rect[i][j] = rectangle[i][j];
            }
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for(int i=row1; i<=row2; i++) {
            for(int j=col1; j<=col2; j++) {
                rect[i][j] = newValue;
            }
        }
    }
    
    int getValue(int row, int col) {    
        return rect[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */
