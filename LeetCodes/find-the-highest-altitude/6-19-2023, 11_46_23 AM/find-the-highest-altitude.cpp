// Link: https://leetcode.com/problems/find-the-highest-altitude

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-highest-altitude
 *  RUNTIME: 6 ms
 *  MEMORY: 8 MB
 *  DATE: 6-19-2023, 11:46:23 AM
 *
 */

// Solution:

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int high = 0, sum = 0;
        for(auto &val: gain) {
            sum += val;
            high = max(high, sum);
        }
        return high;
    }
};
