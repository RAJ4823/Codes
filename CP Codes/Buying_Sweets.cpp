#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, r;
        cin >> n >> r;
        ll a[n], b[n];
        vector<pair<ll, ll>> v;

        for (ll i = 0; i < n; i++)
            cin >> a[i];

        for (ll i = 0; i < n; i++)
            cin >> b[i];

        for (ll i = 0; i < n; i++)
            v.push_back({a[i] - b[i], a[i]});

        sort(v.begin(), v.end());
        ll ans = 0;

        for (ll i = 0; i < n; i++)
        {
            ll price = v[i].second;
            ll diff = v[i].first;
            ll sub = (r - price + diff) / diff;

            if (price <= r) 
            {
                ans += sub;
                r -= (diff * sub);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
