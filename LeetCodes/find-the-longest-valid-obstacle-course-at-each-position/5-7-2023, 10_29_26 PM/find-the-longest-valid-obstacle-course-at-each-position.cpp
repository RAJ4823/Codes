// Link: https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-longest-valid-obstacle-course-at-each-position
 *  RUNTIME: 553 ms
 *  MEMORY: 124.4 MB
 *  DATE: 5-7-2023, 10:29:26 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<int> dp(n, INT_MAX), ans;
        for(int val: obstacles){
            int index = upper_bound(dp.begin(), dp.end(), val) - dp.begin();
            ans.push_back(index + 1);
            dp[index] = val;
        }
        return ans;
    }
};
