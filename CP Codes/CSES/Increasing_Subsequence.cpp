#include <bits/stdc++.h>
using namespace std;

// int fun(int i, int prev, vector<int> &arr, vector<vector<int>> &dp)
// {
//     if (i == 0)
//         return (arr[i] < arr[prev]);
//     if (dp[i][prev] != -1)
//         return dp[i][prev];
//     int notpick = fun(i - 1, prev, arr, dp);
//     int pick = 0;
//     if (arr[i] < arr[prev])
//         pick = 1 + fun(i - 1, i, arr, dp);
//     return dp[i][prev] = max(pick, notpick);
// }

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    arr.push_back(INT_MAX);

    // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    // cout << fun(n - 1, n, arr, dp);

    vector<int> dp(n + 1, 0), temp(n + 1, 0);
    for (int i = 0; i <= n; i++)
        dp[i] = (arr[0] < arr[i]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int pick = 0;
            if (arr[i] < arr[j])
            {
                pick = 1 + dp[i];
                temp[j] = max(dp[j], pick);
            }
            else
            {
                continue;
            }
        }
        dp = temp;
    }
    cout << dp[n];
    return 0;
}