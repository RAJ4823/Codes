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

string solve()
{
    ll n;
    cin >> n;
    vpll v(n + 1);
    v[0] = {0, 0};
    f(i, n) cin >> v[i + 1].first >> v[i + 1].second;

    ll diff1 = 0, diff2 = 0;
    ff(i, 1, n + 1)
    {
        diff1 = v[i].first - v[i - 1].first;
        diff2 = v[i].second - v[i - 1].second;
        if (diff2 >= 0 && diff1 >= diff2)
            continue;
        else
            return "NO\n";
    }
    return "YES\n";
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        cout << solve();
    }
    return 0;
}