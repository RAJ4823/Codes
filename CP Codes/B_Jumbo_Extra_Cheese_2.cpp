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
        ll n;
        cin >> n;
        vpll v(n);
        f(i, n)
        {
            ll x, y;
            cin >> x >> y;
            v[i] = {max(x, y), min(x, y)};
        }
        sort(v.begin(), v.end());
        ll sum = 0;
        f(i, n)
        {
            sum += 2 * v[i].second;
            if (i < n - 1)
                sum += (v[i + 1].first - v[i].first);
        }
        sum += (v[0].first + v[n - 1].first);
        cout << sum << endl;
    }
    return 0;
}