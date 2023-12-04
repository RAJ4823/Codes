// Link: https://leetcode.com/problems/largest-submatrix-with-rearrangements

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: largest-submatrix-with-rearrangements
 *  RUNTIME: 172 ms
 *  MEMORY: 75.4 MB
 *  DATE: 11-26-2023, 2:25:47 PM
 *
 */

// Solution:

class Solution {
public:
    int maxArea(int m, vector<int> height) {
        int area = 0;
        sort(height.begin(), height.end());
        for(int j=0; j<m; j++) {
            area = max(area, height[j] * (m - j));
        }
        return area;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> height(m, 0);
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                height[j] = (matrix[i][j] == 0) ? 0 : height[j] + 1;
            }
            ans = max(ans, maxArea(m, height));
        }
        return ans;
    }
};
