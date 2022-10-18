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
    int t;
    cin >> t;

    while (t--)
    {
        ll n, l, r;
        cin >> n >> l >> r;
        ll v[n + 1];
        f(i, n) cin >> v[i];
        v[n] = INT_MAX;

        sort(v, v + n);
        ll pairs = 0;
        f(i, n - 1)
        {
            ll L = (lower_bound(v + i + 1, v + n, l - v[i]) - v);
            ll R = (upper_bound(v + i + 1, v + n, r - v[i]) - v);
            // cout << v[i] << " : ";
            // db2(L, R);
            pairs += (R - L);
        }
        cout << pairs << endl;
    }
    return 0;
}