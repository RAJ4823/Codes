// Link: https://leetcode.com/problems/non-overlapping-intervals

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: non-overlapping-intervals
 *  RUNTIME: 473 ms
 *  MEMORY: 89.7 MB
 *  DATE: 7-19-2023, 11:28:49 AM
 *
 */

// Solution:

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end(), [&](const vector<int> &a, const vector<int> &b) {
            return a[1] < b[1];
        });

        int count = 1, prev = arr[0][1];
        for(int i=1; i<n; i++) {
            if(arr[i][0] >= prev) {
                count++;
                prev = arr[i][1];
            } 
        }
        return n - count;
    }
};
