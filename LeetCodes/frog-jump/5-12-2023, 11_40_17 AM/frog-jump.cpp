// Link: https://leetcode.com/problems/frog-jump

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: frog-jump
 *  RUNTIME: 244 ms
 *  MEMORY: 232.9 MB
 *  DATE: 5-12-2023, 11:40:17 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> dp;
    int n;
    bool find(vector<int> &stones, int i, int k){
        if(i == n-1)    return true;
        if(i >= n)      return false; 
        if(dp[i][k] != -1) return dp[i][k]; 

        bool ans = false;
        for(int j = -1; j <= 1; j++){
            int jump=k+j;
            if( jump > 0){
                int next = lower_bound(stones.begin(),stones.end(), stones[i]+jump) - stones.begin();
                if(next == n || stones[next] != stones[i] + jump) 
                    continue;
                ans |= find(stones, next, jump);
            }
        }
        return dp[i][k] = ans;
    }
  
    bool canCross(vector<int>& stones) {
        n = stones.size();
        dp.resize(n+1, vector<int> (n+1, -1));
        
        return find(stones, 0, 0);
    }
};
