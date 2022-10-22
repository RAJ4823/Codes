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
        ll n, m;
        cin >> n >> m;
        vll v(n), u(m + 1), w(m);
        f(i, n) cin >> v[i];
        list<ll> que;
        ff(i, 1, m + 1)
        {
            cin >> u[i];
            w[i - 1] = u[i];
        }
        sort(v.rbegin(), v.rend());
        sort(w.begin(), w.end());
        ll sum = 0, j = 0;
        f(i, n)
        {
            if (j < m && u[v[i]] >= w[j])
            {
                sum += w[j];
                j++;
            }
            else
            {
                sum += u[v[i]];
            }
        }
        cout << sum << endl;
    }
    return 0;
}