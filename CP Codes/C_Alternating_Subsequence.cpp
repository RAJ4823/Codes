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

ll maxSum(int i, bool sign, vll &arr, vvll &dp)
{
    if (i == 0)
    {
        if (sign && arr[i] > 0)
            return arr[i];
        if (!sign && arr[i] < 0)
            return arr[i];
        return -1e9;
    }
    if (dp[i][sign] != -1)
        return dp[i][sign];
    ll notpick = -1e9;
    ll pick = -1e9;
    if (sign)
    {
        notpick = maxSum(i - 1, sign, arr, dp);
        if (arr[i] > 0)
            pick = arr[i] + maxSum(i - 1, !sign, arr, dp);
    }
    else
    {
        notpick = maxSum(i - 1, sign, arr, dp);
        if (arr[i] < 0)
            pick = arr[i] + maxSum(i - 1, !sign, arr, dp);
    }

    return dp[i][sign] = max(pick, notpick);
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
        f(i, n) cin >> arr[i];

        vvll dp1(n, vll(2, -1));
        ll sum1 = maxSum(n - 1, true, arr, dp1);
        vvll dp2(n, vll(2, -1));
        ll sum2 = maxSum(n - 1, false, arr, dp2);
        cout << max(sum1, sum2) << endl;
    }
    return 0;
}