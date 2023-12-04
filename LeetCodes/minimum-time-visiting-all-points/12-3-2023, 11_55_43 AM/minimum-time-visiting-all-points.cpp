// Link: https://leetcode.com/problems/minimum-time-visiting-all-points

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-time-visiting-all-points
 *  RUNTIME: 10 ms
 *  MEMORY: 10.5 MB
 *  DATE: 12-3-2023, 11:55:43 AM
 *
 */

// Solution:

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for(int i = 1; i < points.size(); i++) {
            ans += max(abs(points[i][1] - points[i - 1][1]), abs(points[i][0] - points[i - 1][0]));
        }
        return ans;
    }
};
