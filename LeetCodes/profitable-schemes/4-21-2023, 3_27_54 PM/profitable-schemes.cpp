// Link: https://leetcode.com/problems/profitable-schemes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: profitable-schemes
 *  RUNTIME: 194 ms
 *  MEMORY: 13 MB
 *  DATE: 4-21-2023, 3:27:54 PM
 *
 */

// Solution:

class Solution {
public:
    int dp[102][102][102];
    int mod=1e9+7;
    int totalMembers = 0, minProfit = 0;

    int find(int i, int members, int curProfit, vector<int>& group, vector<int>& profit)
    {
        if(i==profit.size())
        {
            if(curProfit >= minProfit && members <= totalMembers) 
                return 1;
            return 0;
        }
        if(members > totalMembers) 
            return 0;
     
        if(dp[i][members][curProfit]!=-1)
            return dp[i][members][curProfit];

        int newProfit = min(curProfit+profit[i], minProfit);
        int newMembers = members+group[i];
        int take = find(i+1, newMembers, newProfit, group, profit);
        int nottake = find(i+1, members, curProfit, group, profit);

        return  dp[i][members][curProfit] = (take  % mod + nottake  % mod )%mod;
    }
    int profitableSchemes(int n, int m, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        totalMembers = n;
        minProfit = m;
        return find(0, 0, 0, group, profit);
        
    }
};
