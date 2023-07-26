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
        ll n, k;
        cin >> n >> k;
        unordered_map<int, int> in;
        unordered_map<int, pair<int, int>> m;

        ll x;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (m.find(x) == m.end())
            {
                m[x] = {i, INT_MIN};
                in[x] = i;
            }
            else
            {
                int fm = m[x].first;
                int sm = m[x].second;
                int dist = i - in[x] - 1;

                if (dist >= fm)
                {
                    sm = fm;
                    fm = dist;
                }
                else if (dist > sm)
                {
                    sm = dist;
                }

                m[x] = {fm, sm};
                in[x] = i;
            }
        }

        for (auto &x : m)
        {
            int fm = x.second.first;
            int sm = x.second.second;
            int dist = n - in[x.first] - 1;

            if (dist >= fm)
            {
                sm = fm;
                fm = dist;
            }
            else if (dist > sm)
            {
                sm = dist;
            }

            m[x.first] = {fm, sm};
        }

        int ans = INT_MAX;
        for (auto &x : m)
        {
            ans = min(ans, max(x.second.first / 2,  x.second.second));
        }
        cout << ans << endl;
    }
    return 0;
}