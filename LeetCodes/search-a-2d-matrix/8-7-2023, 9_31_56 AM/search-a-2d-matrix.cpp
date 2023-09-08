// Link: https://leetcode.com/problems/search-a-2d-matrix

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: search-a-2d-matrix
 *  RUNTIME: 3 ms
 *  MEMORY: 9.6 MB
 *  DATE: 8-7-2023, 9:31:56 AM
 *
 */

// Solution:

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / n][mid % n];

            if (mid_val == target)
                return true;
            else if (mid_val < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
