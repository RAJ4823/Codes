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
#define SIZE 1000001
#define MOD 1000000007LL

// ll fun(ll n, vll &dp)
// {
//     if (n == 0)
//         return 1;
//     if (dp[n] != -1)
//         return dp[n];

//     ll sum = 0;
//     for (ll i = 1; i <= min(6ll, n); i++)
//     {
//         sum = (sum + fun(n - i, dp)) % MOD;
//     }
//     return dp[n] = (sum % MOD);
// }

int main()
{
    ll n;
    cin >> n;

    // recursive DP
    // vll dp(n + 1, -1);
    // cout << fun(n, dp);

    // Iterative DP
    vll dp(n + 1, 0);
    dp[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= min(6ll, i); j++)
            dp[i] = (dp[i] + dp[i - j]) % MOD;

    cout << dp[n];

    return 0;
}