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

void solve()
{
    ll r, c;
    cin >> r >> c;

    vector<double> a, b;
    ll n, m;
    cin >> n;

    f(i, n)
    {
        double x, y;
        cin >> x >> y;
        double dist = sqrt(pow(x, 2) + pow(y, 2));
        if (dist <= r + c)
            a.push_back(dist);
    }
    cin >> m;
    f(i, m)
    {
        double x, y;
        cin >> x >> y;
        double dist = sqrt(pow(x, 2) + pow(y, 2));
        if (dist <= r + c)
            b.push_back(dist);
    }

    ll sa = a.size(), sb = b.size();
    if (min(sa, sb) == 0)
    {
        cout << sa << ' ' << sb << endl;
    }
    else
    {
        ll ans1 = 0, ans2 = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        if (b[0] < a[0])
        {
            f(i, sb) if (b[i] < a[0])
                ans2++;
        }
        else
        {
            f(i, sa) if (a[i] < b[0])
                ans1++;
        }
        cout << ans1 << ' ' << ans2 << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    f(i, t)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}