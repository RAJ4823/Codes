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
#define mod 1000000007LL

int main()
{
    int n, m;
    cin >> n >> m;
    vll v(n + 1, 0);
    ff(i, 1, n + 1) cin >> v[i];
    vvll dp(n + 2, vll(m + 2, 0));

    ff(i, 1, n + 1)
    {
        ff(x, 1, m + 1)
        {
            if (i == 1) // Base case
            {
                if (v[i] == 0 || v[i] == x)
                    dp[i][x] = 1;
            }
            else
            {
                if (v[i] == 0 || v[i] == x)
                    dp[i][x] = ((dp[i - 1][x - 1] + dp[i - 1][x]) % mod + dp[i - 1][x + 1]) % mod;
            }
        }
    }

    ll ans = 0;
    ff(x, 1, m + 1)
        ans = (ans + dp[n][x]) % mod;

    cout << ans << endl;
    return 0;
}