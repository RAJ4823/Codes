// Link: https://leetcode.com/problems/best-team-with-no-conflicts

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-team-with-no-conflicts
 *  RUNTIME: 425 ms
 *  MEMORY: 23.9 MB
 *  DATE: 1-31-2023, 10:13:18 AM
 *
 */

// Solution:

class Solution {
    int n = 0;
    int dp[1005][1005] = {0};
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> player;
        n = scores.size();

        for(int i=0; i<n; i++) {
            player.push_back({ages[i], scores[i]});
        }
        player.push_back({0,0});
        sort(player.begin(), player.end());

        // int ans = find(1, 0, player);
        for(int i = n; i > 0; i--) {
            for(int j = n; j >= 0; j--) {
                int take = -1e9;
                if(player[i].second >= player[j].second) 
                    take = player[i].second + dp[i+1][i];
                dp[i][j] = max(take, dp[i+1][j]); 
            }
        }
        int ans = dp[1][0];
        return ans;
    }
};
