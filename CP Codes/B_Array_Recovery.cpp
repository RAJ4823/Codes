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
        vll v(n), a(n);

        f(i, n) cin >> v[i];
        a[0] = v[0];
        bool flag = true;
        ff(i, 1, n)
        {
            ll x1 = v[i] + a[i - 1];
            ll x2 = a[i - 1] - v[i];

            if (x1 > 0 && x2 > 0 && x1 != x2)
                flag = false;
            else if (max(x1, x2) >= 0)
                a[i] = max(x1, x2);
        }
        if (flag)
        {
            fauto(i, a) cout << i << ' ';
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}