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

void solve()
{
    ll n;
    cin >> n;
    vll v(n), ans(n);
    f(i, n) cin >> v[i];

    ans[0] = v[0];
    ff(i, 1, n)
    {
        ll x = v[i] + ans[i - 1];
        ll y = ans[i - 1] - v[i];
        if (min(x, y) >= 0 && x != y)
        {
            cout << -1 << endl;
            return;
        }
        ans[i] = max(x, y);
    }
    fauto(x, ans) cout << x << " ";
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}