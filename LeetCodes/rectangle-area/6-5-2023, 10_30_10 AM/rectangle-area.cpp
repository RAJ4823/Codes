// Link: https://leetcode.com/problems/rectangle-area

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: rectangle-area
 *  RUNTIME: 13 ms
 *  MEMORY: 6 MB
 *  DATE: 6-5-2023, 10:30:10 AM
 *
 */

// Solution:

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        // coords of intersecting rect
        int L = max(ax1, bx1), R = min(ax2, bx2);
        int B = max(ay1, by1), T = min(ay2, by2);

        int area1 = (ax2 - ax1) * (ay2 - ay1);
        int area2 = (bx2 - bx1) * (by2 - by1);
        if(R - L < 0 || T - B < 0) // No ineresection
            return area1 + area2;

        int intersectionArea = (R - L) * (T - B);
        return area1 + area2 - intersectionArea;
    }
};
