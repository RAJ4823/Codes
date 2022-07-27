#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define pll pair<ll, ll>
#define fauto(i, n) for (auto &i : n)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, n, m) for (int i = (n); i < (m); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, n, m) for (int i = (n); i >= (m); i--)
#define SIZE 1000001
#define MOD 1000000007LL
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        ll ans[n];
        vll v(n + 1, n);
        
        //INPUT
        f(i, m)
        {
            ll x, y;
            cin >> x >> y;
            if (v[x] > y)
                v[x] = y;
        }

        // MAIN CODE
        bool flag = false;
        set<pll, greater<pll>> s1, s2;

        ff(i, 1, n + 1) s1.insert({v[i], i});
        fr(i, n - 1)
        {
            // db1(i);
            while (!s1.empty() && s1.begin()->first == (i + 1))
            {
                ll temp = s1.begin()->second;
                s2.insert({temp, v[temp]});
                s1.erase(s1.begin());
                // db2(temp, s1.begin()->first);
            }

            if (s2.empty())
            {
                cout << -1 << endl;
                flag = true;
                break;
            }

            ll temp = s2.begin()->first;
            ans[i] = temp;

            s2.erase(s2.begin());

            // db2(s2.begin()->first, s2.begin()->second);
        }

        //IF not -1
        if (!flag)
        {
            f(i, n) cout << ans[i] << ' ';
            cout << endl;
        }
    }
    return 0;
}