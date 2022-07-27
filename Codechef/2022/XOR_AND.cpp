#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        map<ll, ll> m;
        ll ans = 0;
        ll v;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            v = log2(a[i]);
            m[v]++;
        }
        for (ll i = 0; i < n; i++)
        {
            v = log2(a[i]);
            m[v]--;
            ans += m[v];
        }
        cout << ans << endl;
    }
    return 0;
}