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

ll get(ll i, vll &v)
{
    return (max(0ll, (max(v[i - 1], v[i + 1]) - v[i] + 1)));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vll v(n + 1, 0);
        ll ans = 0, count = 0, diff;

        ff(i, 1, n + 1) cin >> v[i];
        ff(i, 2, n) ans += get(i++, v);
        if (n % 2)
        {
            cout << ans << endl;
        }
        else
        {
            ll total = ans;
            for (ll i = n - 1; i > 1; i -= 2)
            {
                total -= get(i - 1, v);
                total += get(i, v);
                ans = min(ans, total);
            }
            cout << ans << endl;
        }
    }
    return 0;
}