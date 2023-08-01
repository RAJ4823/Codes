// Link: https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-groups-entering-a-competition
 *  RUNTIME: 79 ms
 *  MEMORY: 56.6 MB
 *  DATE: 3-16-2023, 8:36:18 AM
 *
 */

// Solution:

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        return sqrt(2 * grades.size() + 0.25) - 0.5;
    }
};
