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

double dist(double x1, double x2, double y1, double y2)
{
    return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}

int main()
{
    int t;
    cin >> t;

    f(tc, t)
    {
        double a, b, c, d;
        cin >> a >> b >> c >> d;
        double x, y, n;
        cin >> x >> y >> n;

        ll maxRad = LONG_LONG_MAX;

        double dist1 = dist(x, x, y, b);
        double dist2 = dist(x, x, y, d);
        double dist3 = dist(a, x, y, y);
        double dist4 = dist(c, x, y, y);
        maxRad = (ll)min({dist1, dist2, dist3, dist4});

        // cout << maxRad << endl;

        vpll ins;
        f(tree, n)
        {
            double xc, yc, rc;
            cin >> xc >> yc >> rc;
            double distc = dist(x, xc, y, yc);
            ll mindist = floor(distc - rc);
            ll maxdist = ceil(distc + rc);
            ins.push_back({mindist, maxdist});
            // cout << mindist << ' ' << maxdist << endl;
        }

        sort(ins.begin(), ins.end());
        vpll merged;
        merged.push_back(ins[0]);

        ll end = ins[0].second;
        ll ans = min(ins[0].first, maxRad);

        ff(i, 1, ins.size())
        {
            if (ins[i].first > maxRad || ins[i].second > maxRad)
                break;
            if (ins[i].first < end)
            {
                end = ins[i].second;
            }
            else
            {
                ans += (end - ins[i].first + 1);
                end = ins[i].second;
            }
        }

        if (ins.back().second <= maxRad)
            ans += (maxRad - ins.back().second + 1);
        
        cout << "Case " << tc + 1 << ": ";
        cout << ans << endl;
    }
    return 0;
}