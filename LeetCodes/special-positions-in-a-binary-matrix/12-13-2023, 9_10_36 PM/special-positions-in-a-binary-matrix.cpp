// Link: https://leetcode.com/problems/special-positions-in-a-binary-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: special-positions-in-a-binary-matrix
 *  RUNTIME: 18 ms
 *  MEMORY: 13.1 MB
 *  DATE: 12-13-2023, 9:10:36 PM
 *
 */

// Solution:

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                if (mat[i][j] == 1 && accumulate(mat[i].begin(), mat[i].end(), 0) == 1 &&
                    accumulate(mat.begin(), mat.end(), 0, [j](int sum, const vector<int>& row) { return sum + row[j]; }) == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};
