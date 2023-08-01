// Link: https://leetcode.com/problems/new-21-game

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: new-21-game
 *  RUNTIME: 4 ms
 *  MEMORY: 9.1 MB
 *  DATE: 5-25-2023, 11:07:24 AM
 *
 */

// Solution:

class Solution {
public:
    double new21Game(int N, int K, int MAX) {
        if (K == 0) return 1.0;
        if (N >= K + MAX - 1) return 1.0;
        vector<double> dp(N + 1, 0.0);

        double prb = 0.0;
        double sum = 1.0; 
        dp[0] = 1.0;

        for (int i = 1; i <= N; i++) {
            dp[i] = sum / MAX;
            
            if(i >= K)  
                prb += dp[i];
            else        
                sum += dp[i];

            if(i >= MAX) 
                sum -= dp[i - MAX];
        }

        return prb;
    }
};
