// Link: https://leetcode.com/problems/stone-game-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: stone-game-ii
 *  RUNTIME: 3 ms
 *  MEMORY: 42.2 MB
 *  DATE: 8-20-2024, 10:56:13 AM
 *
 */

// Solution:

class Solution {
    int dp[][];
    int sum[];
    int n;

    public void init(int[] piles) {
        n = piles.length;
        dp = new int[n][n];
        Arrays.stream(dp).forEach(arr -> Arrays.fill(arr, -1));
        
        sum = new int[n];
        sum[n-1] = piles[n-1];
        for(int i=n-2; i>=0; i--) {
            sum[i] = sum[i+1] + piles[i];
        }
    }

    public int find(int i, int m, int[] piles) {
        if(i + 2 * m >= n) return sum[i];
        if(dp[i][m] != -1) return dp[i][m];

        int maxi = 0;
        for(int j=1; j<=2*m; j++) {
            maxi = Math.max(maxi, sum[i] - find(i + j, Math.max(j, m), piles));
        }
        return dp[i][m] = maxi;
    }

    public int stoneGameII(int[] piles) {
        init(piles);
        int ans = find(0, 1, piles);
        return ans;
    }
}
