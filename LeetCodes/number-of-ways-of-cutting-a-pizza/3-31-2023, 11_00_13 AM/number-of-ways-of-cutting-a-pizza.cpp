// Link: https://leetcode.com/problems/number-of-ways-of-cutting-a-pizza

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: number-of-ways-of-cutting-a-pizza
 *  RUNTIME: 49 ms
 *  MEMORY: 8.4 MB
 *  DATE: 3-31-2023, 11:00:13 AM
 *
 */

// Solution:

class Solution {
public:
    int n = 0, m = 0, MOD = 1e9+7;
    vector<vector<vector<int>>> dp;
    vector<vector<int>> ps;

    void fillPrefixSum(vector<string> &pizza) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
                if(pizza[i-1][j-1] == 'A') {
                    ps[i][j]++;
                }
            }
        }
    }

    bool hasApple(int startRow, int startCol, int endRow, int endCol) {
        int sum1 = ps[endRow][endCol] + ps[startRow][startCol];
        int sum2 = ps[startRow][endCol] + ps[endRow][startCol];
        int apples = sum1 - sum2;
        return (apples > 0);
    }

    int find(int row, int col, int rem, vector<string> &pizza) {
        if(row >= n || col >= m)    return 0;
        if(dp[row][col][rem] != -1) return dp[row][col][rem];
        if(rem == 1)                return hasApple(row, col, n, m);
        
        int ways = 0;
        for(int i = row; i < n; i++) {
            if(hasApple(row, col, i + 1, m)) {
                ways = (ways + find(i + 1, col, rem - 1, pizza)) % MOD;
            }
        }

        for(int j = col; j < m; j++) {
            if(hasApple(row, col, n, j + 1)) {
                ways = (ways + find(row, j + 1, rem - 1, pizza)) % MOD;
            }
        }

        return dp[row][col][rem] = ways;
    }

    int ways(vector<string>& pizza, int k) {
        n = pizza.size();
        m = pizza[0].size();
        
        dp.resize(n, vector<vector<int>> (m, vector<int> (k+1, -1)));
        ps.resize(n + 1, vector<int> (m + 1, 0));
        fillPrefixSum(pizza);

        return find(0, 0, k, pizza);
    }
};
