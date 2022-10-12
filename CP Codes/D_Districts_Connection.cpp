#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define fauto(i, v) for (auto &i : v)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, v, b) for (int i = (v); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, v, b) for (int i = (v); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

void solve(vll &v, int n)
{
    vpll ans;
    ll j = -1;
    ff(i, 1, n)
    {
        if (v[i] != v[0])
            j = i;
    }

    ff(i, 1, n)
    {
        if (v[i] == v[0])
            ans.push_back({j + 1, i + 1});
        else
            ans.push_back({1, i + 1});
    }

    if (j == -1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    fauto(i, ans) cout << i.first << ' ' << i.second << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n);
        f(i, n) cin >> v[i];
        solve(v, n);
    }
    return 0;
}