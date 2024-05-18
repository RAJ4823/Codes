// Link: https://leetcode.com/problems/find-the-town-judge

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-town-judge
 *  RUNTIME: 133 ms
 *  MEMORY: 72.9 MB
 *  DATE: 2-22-2024, 11:01:02 AM
 *
 */

// Solution:

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts[n+1], rev[n+1];
        for(auto &data: trust) {
            int a = data[0];
            int b = data[1];
            trusts[a].push_back(b);
            rev[b].push_back(a);
        }
        for(int i = 1; i<=n; i++) {
            if(trusts[i].size() == 0 && rev[i].size() == (n-1)) {
                return i;
            }
        }
        return -1;
    }
};
