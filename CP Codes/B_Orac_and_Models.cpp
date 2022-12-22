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

ll find(int i, int prev, vll &arr, vvll &dp)
{
    if (i == 0)
    {
        if (prev < arr.size())
            return (arr[i] < arr[prev] && arr[prev] % arr[i] == 0);
        return 1;
    }
    if (dp[i][prev] != -1)
        return dp[i][prev];

    ll take = -1e9, nottake = -1e9;
    if (prev == arr.size())
        take = 1 + find(i - 1, i, arr, dp);
    else if (arr[i] < arr[prev] && arr[prev] % arr[i] == 0)
        take = 1 + find(i - 1, i, arr, dp);
    nottake = find(i - 1, prev, arr, dp);

    return dp[i][prev] = max(take, nottake);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vll arr(n);
        vvll dp(n, vll(n + 1, -1));

        f(i, n) cin >> arr[i];

        ll ans = find(n - 1, n, arr, dp);
        cout << ans << endl;
    }
    return 0;
}