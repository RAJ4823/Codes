// Link: https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: last-moment-before-all-ants-fall-out-of-a-plank
 *  RUNTIME: 26 ms
 *  MEMORY: 23.1 MB
 *  DATE: 11-4-2023, 4:49:14 PM
 *
 */

// Solution:

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int time = 0;
        for(auto &pos: left)
            time = max(time, pos);
        for(auto &pos: right) 
            time = max(time, n - pos);
        return time;
    }
};
