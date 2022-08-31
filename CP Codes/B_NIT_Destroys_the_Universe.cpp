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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll x, count = 0, ans = 0;
        vll v(n);
        f(i, n)
        {
            cin >> x;
            v[i] = x;
            if (x != 0)
            {
                count = 1;
            }
            else
            {
                ans += count;
                count = 0;
            }
        }
        ans += count;
        if (v[0] == 0 || v[n - 1] == 0)
        {
            ans = min(2ll, ans);
        }
        cout << ans << endl;
    }
    return 0;
}