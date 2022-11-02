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
    ll n, m;
    cin >> n >> m;
    vll v(n + 1, 0);
    f(i, n)
    {
        ll x;
        cin >> x;
        v[i + 1] = v[i] + x;
    }
    ll i = 0, j = 1;
    ll ans = 0;
    while (j <= n)
    {
        if (v[j] - v[i] <= m)
        {
            // db2(i, j);
            ans = max(ans, j - i);
            j++;
        }
        else
        {
            i++;
            if (i == j)
                j++;
        }
    }
    cout << ans << endl;

    return 0;
}