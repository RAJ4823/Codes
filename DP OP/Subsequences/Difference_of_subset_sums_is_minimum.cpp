//?https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?leftPanelTab=0
#include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int> &a, int n)
{
    // Calc of Total Sum
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += a[i];
    vector<vector<bool>> dp(n, vector<bool>(totalSum + 1, false));

    // Base cases
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (a[0] <= totalSum)
        dp[0][a[0]] = true;

    // Tabulation DP
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= totalSum; target++)
        {
            bool pick = false, notp = false;
            notp = dp[i - 1][target];
            if (target >= a[i])
                pick = dp[i - 1][target - a[i]];
            dp[i][target] = (pick || notp);
        }
    }

    // Finding minimum diff by each Possible sum
    int mini = 1e9;
    for (int currSum = 0; currSum <= totalSum; currSum++)
    {
        if (dp[n - 1][currSum])
        {
            int sum1 = currSum;
            int sum2 = totalSum - currSum;
            mini = min(mini, abs(sum1 - sum2));
        }
    }
    return mini;
}
