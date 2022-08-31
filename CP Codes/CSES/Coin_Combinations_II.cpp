
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define fauto(i, a) for (auto &i : a)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001ll
#define N 101ll
#define MOD 1000000007LL

//? Recursive Dp
//! ERROR
int fun(int n, int sum, vector<int> &a, vector<vector<int>> &dp)
{
    if (sum == 0)
        return 1;
    if (n == 0)
    {
        if (sum == a[0])
            return 1;
        else
            return 0;
    }

    if (dp[n][sum] != -1)
        return dp[n][sum];

    bool pickandstay = 0, notpick = 0, pickandmove = 0;

    notpick = fun(n - 1, sum, a, dp) % MOD;
    if (sum >= a[n])
    {
        pickandstay = fun(n, sum - a[n], a, dp) % MOD;
        pickandmove = fun(n - 1, sum - a[n], a, dp) % MOD;
    }
    return dp[n][sum] = (notpick + pickandstay) % MOD;
}
int main()
{
    int n, sum;
    cin >> n >> sum;

    vector<int> a(n);
    f(i, n) cin >> a[i];

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    cout << fun(n - 1, sum, a, dp);

    // //? Iterative DP
    // vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));
    // dp[0][0] = 1;

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int s = 0; s <= sum; s++)
    //     {
    //         dp[i][s] = dp[i - 1][s];
    //         ll prev = s - a[i - 1];
    //         if (prev >= 0)
    //             (dp[i][s] += dp[i][prev]) %= MOD;
    //     }
    // }
    // cout << dp[n][sum];

    return 0;
}
