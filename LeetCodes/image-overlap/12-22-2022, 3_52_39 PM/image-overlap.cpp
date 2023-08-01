// Link: https://leetcode.com/problems/image-overlap

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: image-overlap
 *  RUNTIME: 366 ms
 *  MEMORY: 10.1 MB
 *  DATE: 12-22-2022, 3:52:39 PM
 *
 */

// Solution:

class Solution {
private:
    int findOverlaps(int x, int y, int n, vector<vector<int>>&c, vector<vector<int>>&b) {
        int sum = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                sum += (b[i][j] * c[x+i][y+j]);
            }
        }
        return sum;
    }
public:
    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        int m = 3*n; 
        vector<vector<int>> c(m, vector<int> (m, 0));

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                c[n+i][n+j] = a[i][j];
            }
        }

        int ans = 0;
        for(int i=0; i<2*n; i++) {
            for(int j=0; j<2*n; j++) {
                int overlaps = findOverlaps(i, j, n, c, b);
                ans = max(ans, overlaps);
            }
        }
        return ans;
    }
};
