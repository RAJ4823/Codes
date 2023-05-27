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

        vll v(n);
        f(i, n) cin >> v[i];

        ll maxval = (v[0] == n) ? (n - 1) : n;
        ll maxind = 0;
        f(i, n) if (v[i] == maxval) maxind = i;

        vll ans;
        for (int i = maxind; i < n; i++)
            ans.push_back(v[i]);

        if (ans.size() < n)
        {
            int i, j = maxind - 1;
            if (maxind < n-1)
                ans.push_back(v[j--]);

            for (j; j > 0; j--)
            {
                if (v[j] > v[0])
                    ans.push_back(v[j]);
                else
                    break;
            }
            for (i = 0; i <= j; i++)
            {
                ans.push_back(v[i]);
            }
        }
        f(i, n)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}