#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define pll pair<ll, ll>
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

ll find(int i, int j, vvll &arr, vvll &dp)
{
    if (j == 0)
        return arr[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];

    ll take = arr[i][j] + find(!i, j - 1, arr, dp);
    ll nottake = find(i, j - 1, arr, dp);
    return dp[i][j] = max(take, nottake);
}

int main()
{
    int n;
    cin >> n;
    vvll arr(2, vll(n));
    vvll dp(2, vll(n, 0));
    f(j, n) cin >> arr[0][j];
    f(j, n) cin >> arr[1][j];

    //! Recursive DP
    // ll ans = max(find(0, n - 1, arr, dp), find(1, n - 1, arr, dp));

    //! Iterative DP
    // dp[0][0] = arr[0][0];
    // dp[1][0] = arr[1][0];
    // for (int j = 1; j < n; j++)
    // {
    //     dp[0][j] = max(arr[0][j] + dp[1][j - 1], dp[0][j - 1]);
    //     dp[1][j] = max(arr[1][j] + dp[0][j - 1], dp[1][j - 1]);
    // }
    // ll ans = max(dp[0][n - 1], dp[1][n - 1]);

    //! Space Optimized
    ll prev0 = arr[0][0], val0;
    ll prev1 = arr[1][0], val1;
    for (int j = 1; j < n; j++)
    {
        val0 = max(arr[0][j] + prev1, prev0);
        val1 = max(arr[1][j] + prev0, prev1);
        prev0 = val0;
        prev1 = val1;
    }
    ll ans = max(prev0, prev1);

    cout << ans << endl;
    return 0;
}