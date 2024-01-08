// Link: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: widest-vertical-area-between-two-points-containing-no-points
 *  RUNTIME: 257 ms
 *  MEMORY: 82.6 MB
 *  DATE: 12-21-2023, 10:32:44 AM
 *
 */

// Solution:

class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> st;
        for(auto &x: points) 
            st.insert(x[0]);
        int maxWidth = 0;
        vector<int> xPoints(st.begin(), st.end());
        for(int i=0; i<xPoints.size() - 1; i++) {
            maxWidth = max(maxWidth, xPoints[i+1] - xPoints[i]);
        }
        return maxWidth;
    }
};
