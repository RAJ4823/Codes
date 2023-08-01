// Link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-arrows-to-burst-balloons
 *  RUNTIME: 1004 ms
 *  MEMORY: 89.8 MB
 *  DATE: 1-5-2023, 4:03:24 PM
 *
 */

// Solution:

class Solution {
    
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;
        sort(points.begin(), points.end(), [](const vector<int> &x, const vector<int> &y) {return (x[1] < y[1]); });
        int i = 0, j = 0, count = 0;
        while(i < n) {
            if(count == 0 || points[i][0] > points[j][1]){
                count++;
                j = i;
            }
            i++;
        }
        return count;
    }
};
