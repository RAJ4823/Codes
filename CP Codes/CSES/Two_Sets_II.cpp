#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;

ll getWays(int n, int tar)
{
    vector<ll> dp(tar + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n - 1; i++)
    {
        for (int sum = tar; sum >= i; sum--)
        {
            (dp[sum] += dp[sum - i] % mod) %= mod;
        }
    }
    return dp[tar] % mod;
}
int main()
{
    int n;
    cin >> n;
    int totalSum = n * (n + 1) / 2;
    ll ans = 0;

    if (totalSum % 2 == 0)
        ans = getWays(n, totalSum / 2);
    cout << ans;

    return 0;
}