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
    ll l, n;
    cin >> l >> n;
    vector<pair<ll, char>> v(n);

    f(i, n)
    {
        cin >> v[i].first >> v[i].second;
    }
    vll a;
    ll sum1 = 0, sum2 = 0;
    f(i, n)
    {
        if (v[i].second == 'C')
        {
            sum1 += v[i].first;
            if (sum2 > 0)
            {
                a.push_back(sum2);
                sum2 = 0;
            }
        }
        else
        {
            sum2 += v[i].first;
            if (sum1 > 0)
            {
                a.push_back(sum1);
                sum1 = 0;
            }
        }
    }
    if (sum1 > 0 || sum2 > 0)
        a.push_back(max(sum1, sum2));

    ll ans = 0;
    f(i, a.size() - 1)
    {
        ans += (a[i] / l);
        a[i + 1] -= (a[i] % l);
    }
    ans += a[a.size() - 1] / l;
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