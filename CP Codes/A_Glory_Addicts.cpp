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
        int n;
        cin >> n;
        vpll v(n);
        f(i, n) cin >> v[i].first;
        f(i, n) cin >> v[i].second;
        vll zero, one;
        ll ans = 0;
        f(i, n)
        {
            if (v[i].first)
                one.push_back(v[i].second);
            else
                zero.push_back(v[i].second);
            ans += v[i].second;
        }
        sort(one.begin(), one.end());
        sort(zero.begin(), zero.end());
        ll p = one.size();
        ll q = zero.size();
        ll j = min(p, q);

        for (int i = 0; i < j; i++)
            ans += (one[p - i - 1] + zero[q - i - 1]);
        if (p == q)
            ans -= min(one[0], zero[0]);

        cout << ans << endl;
    }
    return 0;
}