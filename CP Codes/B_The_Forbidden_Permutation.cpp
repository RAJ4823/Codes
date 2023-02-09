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
        ll n, m, d;
        cin >> n >> m >> d;
        vll p(n), a(m);
        mll index;

        f(i, n)
        {
            cin >> p[i];
            index[p[i]] = i;
        }
        f(i, m)
        {
            cin >> a[i];
        }

        ll moves = INT_MAX;
        f(i, m - 1)
        {
            ll diff = index[a[i + 1]] - index[a[i]];
            if (diff < 0 || diff > d)
            {
                moves = 0;
                break;
            }
            else
            {
                if (d + 1 < n)
                    diff = min(diff, d - diff + 1);
                moves = min(moves, diff);
            }
        }
        cout << moves << endl;
    }
    return 0;
}