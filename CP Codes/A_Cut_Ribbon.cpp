#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define vi vector<int>
#define vvi vector<vi>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define fauto(i, a) for (auto &i : a)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define MAXI 1e9
#define MOD 1000000007LL

ll solve(int i, vi &arr, vi &dp)
{
    if (i < 0)
        return -1e9;
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans1 = 0, ans2 = 0, ans3 = 0;
    ans1 = 1 + solve(i - arr[0], arr, dp);
    ans2 = 1 + solve(i - arr[1], arr, dp);
    ans3 = 1 + solve(i - arr[2], arr, dp);
    return dp[i] = max(ans1, max(ans2, ans3));
}

int main()
{
    int n;
    cin >> n;
    vi arr(3), dp(n + 1, -1);
    f(i, 3) cin >> arr[i];
    ll ans = solve(n, arr, dp);
    cout << ans << endl;
    return 0;
}