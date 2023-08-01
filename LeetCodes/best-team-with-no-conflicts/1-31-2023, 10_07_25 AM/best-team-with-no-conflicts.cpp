// Link: https://leetcode.com/problems/best-team-with-no-conflicts

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: best-team-with-no-conflicts
 *  RUNTIME: 440 ms
 *  MEMORY: 23.9 MB
 *  DATE: 1-31-2023, 10:07:25 AM
 *
 */

// Solution:

class Solution {
    int n = 0;
    int dp[1005][1005] = {0};
public:
    int find(int curr, int prev, vector<pair<int,int>> &player) {
        if(curr == n+1) return 0;
        if(dp[curr][prev] > 0) return dp[curr][prev];

        int take = -1e9, not_take = -1e9;
        if(player[curr].second >= player[prev].second) {
            take = player[curr].second + find(curr+1, curr, player);
        }
        not_take = find(curr+1, prev, player);

        return dp[curr][prev] = max(take, not_take);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int,int>> player;
        n = scores.size();

        for(int i=0; i<n; i++) {
            player.push_back({ages[i], scores[i]});
        }
        player.push_back({0,0});
        sort(player.begin(), player.end());

        int ans = find(1, 0, player);
        return ans;
    }
};
