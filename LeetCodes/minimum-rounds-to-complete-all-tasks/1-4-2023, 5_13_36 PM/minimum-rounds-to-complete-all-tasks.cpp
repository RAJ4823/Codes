// Link: https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-rounds-to-complete-all-tasks
 *  RUNTIME: 497 ms
 *  MEMORY: 103.7 MB
 *  DATE: 1-4-2023, 5:13:36 PM
 *
 */

// Solution:

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> m;
        for(auto &val: tasks)
            m[val]++;

        int count = 0;
        for(auto &x: m) {
            if(x.second < 2) return -1;
            if(x.second == 2) count++;
            else count += ((x.second+2)/3);
        }
        return count;
    }
};
