// Link: https://leetcode.com/problems/flipping-an-image

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: flipping-an-image
 *  RUNTIME: 7 ms
 *  MEMORY: 9.2 MB
 *  DATE: 9-16-2023, 2:56:15 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        vector<vector<int>> ans(n, vector<int> (n));

        for(int i=0; i<n; i++) {
            for(int j=n-1; j>=0; j--) {
                ans[i][n - 1 - j] = !image[i][j];
            }
        }
        return ans;
    }
};
