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
    vll v(n + 1), sum(n + 1, 0);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum[i] = sum[i - 1] + v[i];
    }

    ll temp = 0, j = 0;
    for (int i = 1; i <= n; i++)
    {
        temp += v[i];
        if (temp < 0)
        {
            while (v[i] < 0 && i <= n)
                i++;
            db2(v[i], ans);
            temp = v[i];
        }
        ans += temp;
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    f(i, t)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}