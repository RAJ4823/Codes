// Link: https://leetcode.com/problems/merge-intervals

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: merge-intervals
 *  RUNTIME: 42 ms
 *  MEMORY: 19 MB
 *  DATE: 1-16-2023, 10:33:56 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        int i = 0, j = -1, n = intervals.size();
        while(i < n) {
            if (j == -1 || ans[j][1] < intervals[i][0]) {
                ans.push_back({intervals[i][0], intervals[i][1]});
                j++;
            }
            else {
                ans[j][1] = max(ans[j][1], intervals[i][1]);
            }
            i++;
        }
        return ans;
    }
};
