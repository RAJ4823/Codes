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
        ll n, k, maxi = 0;
        cin >> n >> k;

        vll v(n);
        set<ll> s;
        f(i, n)
        {
            cin >> v[i];
            s.insert(v[i]);
        }

        if (s.size() > k)
        {
            cout << -1 << endl;
        }
        else
        {
            vll arr, dist;
            ll i = 1, j = 0;

            while (s.size() < k && i <= n)
            {
                s.insert(i);
                i++;
            }
            fauto(i, s) dist.push_back(i);
            i = 0;
            while (i < n)
            {
                if (dist[j] == v[i])
                    i++;
                arr.push_back(dist[j]);
                j = (j + 1) % (s.size());
            }

            cout << arr.size() << endl;
            fauto(val, arr) cout << val << ' ';
            cout << endl;
        }
    }
    return 0;
}