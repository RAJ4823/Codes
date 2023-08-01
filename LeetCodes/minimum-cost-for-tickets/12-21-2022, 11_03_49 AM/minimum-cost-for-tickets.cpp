// Link: https://leetcode.com/problems/minimum-cost-for-tickets

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-cost-for-tickets
 *  RUNTIME: 7 ms
 *  MEMORY: 9.4 MB
 *  DATE: 12-21-2022, 11:03:49 AM
 *
 */

// Solution:

class Solution {
private:
    int find(vector<int>& days, vector<int>& costs, int i, int dp[])  {
        if(i >= days.size())    return 0;
        if(dp[days[i]] != 0)    return dp[days[i]];
        
        int k = i, j = i;
        while(k < days.size() && days[i] + 7 > days[k]) ++k;
        while(j < days.size() && days[i] + 30 > days[j]) ++j;

        int case1 = costs[0] + find(days, costs, i + 1, dp);
        int case2 = costs[1] + find(days, costs, k, dp);
        int case3 = costs[2] + find(days, costs, j, dp);
        
        return dp[days[i]] = min(case1, min(case2, case3));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[366] = {0};
        sort(days.begin(), days.end());
        int ans = find(days, costs, 0, dp);
        return ans;
    }
};
