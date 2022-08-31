
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

vll a(SIZE);

//? Recursive Dp
// vll dp(SIZE, -1);
// int fun(ll n, ll sum)
// {
//     if (sum == 0)
//         return 1;
//     if (sum < 0)
//         return 0;
//     if (dp[sum] != -1)
//         return dp[sum];

//     ll steps = 0;
//     for (int i = 0; i < n; i++)
//         steps = (steps + fun(n, sum - a[i])) % MOD;

//     return dp[sum] = (steps % MOD);
// }
int main()
{
    ll n, sum;
    cin >> n >> sum;

    f(i, n) cin >> a[i];
    // cout << fun(n, sum);

    //? Iterative DP
    vll dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - a[j] < 0)
                continue;
            dp[i] = (dp[i] + dp[i - a[j]]) % MOD;
        }
    }
    cout << dp[sum];
    
    return 0;
}