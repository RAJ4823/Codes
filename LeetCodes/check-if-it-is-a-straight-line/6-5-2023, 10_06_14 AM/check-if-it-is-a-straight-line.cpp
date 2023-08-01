// Link: https://leetcode.com/problems/check-if-it-is-a-straight-line

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: check-if-it-is-a-straight-line
 *  RUNTIME: 13 ms
 *  MEMORY: 10.4 MB
 *  DATE: 6-5-2023, 10:06:14 AM
 *
 */

// Solution:

class Solution {
public:
    double getSlope(vector<int> a, vector<int> b) {
        double diffY = (double)(b[1]) - (double)(a[1]);
        double diffX = (double)(b[0]) - (double)(a[0]);

        if(diffX == 0) return INT_MAX;
        return diffY / diffX;
    }
    bool checkStraightLine(vector<vector<int>>& arr) {
        double slope = getSlope(arr[0], arr[1]);
        for(int i=2; i<arr.size(); i++) {
            if(slope != getSlope(arr[0], arr[i]))
                return false;
        }
        return true;
    }
};
