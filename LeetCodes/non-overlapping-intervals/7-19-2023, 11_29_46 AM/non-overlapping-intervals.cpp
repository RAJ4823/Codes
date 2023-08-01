// Link: https://leetcode.com/problems/non-overlapping-intervals

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: non-overlapping-intervals
 *  RUNTIME: 469 ms
 *  MEMORY: 89.6 MB
 *  DATE: 7-19-2023, 11:29:46 AM
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

        int count = n-1, prev = 0;
        for(int i=1; i<n; i++) {
            if(arr[i][0] >= arr[prev][1]) {
                count--;
                prev = i;
            } 
        }
        return count;
    }
};
