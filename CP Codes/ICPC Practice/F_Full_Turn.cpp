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
        map<pair<ll, ll>, ll> m;
        ll pos_inf = 0, neg_inf = 0;
        ll pos_flat = 0, neg_flat = 0;
        while (n--)
        {
            ll x, y, a, b;
            cin >> x >> y >> a >> b;
            if (x - a == 0)
            {
                if (y - b >= 0)
                    pos_inf++;
                else
                    neg_inf++;
            }
            else if (y - b == 0)
            {
                if (x - a > 0)
                    pos_flat++;
                else
                    neg_flat++;
            }
            else
            {
                ll gcd = abs(__gcd((y - b), (x - a)));
                ll diffx = (x - a) / gcd;
                ll diffy = (y - b) / gcd;
                m[{diffx, diffy}]++;
            }
        }

        ll ans = 0;
        for (auto &val : m)
        {
            auto pos = val.first;
            pair<ll,ll> neg = {-pos.first, -pos.second};
            ans += m[pos] * m[neg];
            m.erase(neg);
        }
        ans += (pos_inf * neg_inf);
        ans += (pos_flat * neg_flat);
        cout << ans << endl;
    }
    return 0;
}