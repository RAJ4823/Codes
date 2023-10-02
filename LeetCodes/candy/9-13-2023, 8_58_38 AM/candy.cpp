// Link: https://leetcode.com/problems/candy

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: candy
 *  RUNTIME: 23 ms
 *  MEMORY: 17.7 MB
 *  DATE: 9-13-2023, 8:58:38 AM
 *
 */

// Solution:

class Solution {
public:
  int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> dp(n, 1);

    for(int i=1; i<n; i++) {
      if(ratings[i] > ratings[i-1]) {
        dp[i] = dp[i-1] + 1;
      }
    }

    int ans = dp[n-1];
    for(int i=n-2; i>=0; i--) {
      if(ratings[i] > ratings[i+1]) {
        dp[i] = max(dp[i], dp[i+1] + 1);
      }
      ans += dp[i];
    }
    return ans;
  }
};
