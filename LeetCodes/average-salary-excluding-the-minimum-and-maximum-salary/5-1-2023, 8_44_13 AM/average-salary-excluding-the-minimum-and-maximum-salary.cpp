// Link: https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: average-salary-excluding-the-minimum-and-maximum-salary
 *  RUNTIME: 5 ms
 *  MEMORY: 7.1 MB
 *  DATE: 5-1-2023, 8:44:13 AM
 *
 */

// Solution:

class Solution {
public:
    double average(vector<int>& salary) {
        double total = 0.0;
        double mini = salary[0];
        double maxi = salary[0];

        for(double val: salary) {
            total += val;
            mini = min(mini, val);
            maxi = max(maxi, val);
        }
        total -= (mini + maxi);
        return total/(salary.size()-2);
    }
};
