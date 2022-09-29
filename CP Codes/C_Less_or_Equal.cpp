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
    ll n, k;
    cin >> n >> k;
    vll v(n + 1);
    f(i, n) cin >> v[i];
    v[n] = INT_MAX;

    sort(v.begin(), v.end());
    ll ans = -1;

    if (k == 0)
        ans = (v[0] == 1) ? -1 : 1;
    else if (v[k - 1] != v[k])
        ans = v[k - 1];
    cout << ans << endl;
    return 0;
}