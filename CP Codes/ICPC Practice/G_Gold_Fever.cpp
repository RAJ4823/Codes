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

ll ans(int i, vll &gold, vpll &v, vll &dp)
{
    if (i >= gold.size())
        return 0;

    if (dp[i] != -1)
        return dp[i];
    ll take = 0, dont = 0;
    ll x = v[i].first;
    ll y = v[i].second;
    for (ll j = i + x; j <= i + y; j++)
    {
        take = max(take, gold[i] + ans(j, gold, v, dp));
    }
    dont = ans(i + 1, gold, v, dp);

    return dp[i] = max(take, dont);
}
void solve()
{
    ll n;
    cin >> n;
    vpll v(n);

    vll gold(n);
    for (ll i = 0; i < n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        gold[i] = a;
        v[i] = {b, c};
    }
    vll dp(n, -1);
    ll maxi = ans(0, gold, v, dp);
    f(i, n) maxi = max(maxi, dp[i]);
    cout << maxi << endl;
}

int main()
{
    solve();
    return 0;
}