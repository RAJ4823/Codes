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

int solve(int l, int r, ll &ans, vll &v)
{
    if (l == r)
        return v[l];
    ll mid = (l + r / 2);
    ll left = solve(0, mid, ans, v);
    ll right = solve(mid, r, ans, v);
    if (left > right)
        ans++;
    return (left + right);
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
        ll ans = 0;
        int temp = solve(0, n - 1, ans, v);
        cout << ans << endl;
    }
    return 0;
}