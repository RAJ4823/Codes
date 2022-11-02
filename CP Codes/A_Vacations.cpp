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

int main()
{
    ll n;
    cin >> n;
    vll v(n + 1);
    ff(i, 1, n + 1) cin >> v[i];
    vvll dp(n + 1, vll(3, 0));

    // for 0 based indexing
    // if (v[0] == 1 || v[0] == 3)
    //     dp[0][1] = 1;
    // if (v[0] == 2 || v[0] == 3)
    //     dp[0][2] = 1;

    ff(i, 1, n + 1)
    {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
        if (v[i] == 1 || v[i] == 3)
        {
            dp[i][1] = 1 + max(dp[i - 1][0], dp[i - 1][2]);
        }
        if (v[i] == 2 || v[i] == 3)
        {
            dp[i][2] = 1 + max(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    ll ans = max(dp[n][0], max(dp[n][1], dp[n][2]));
    cout << n - ans << endl;
    return 0;
}