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
        ll n, q;
        cin >> n >> q;
        vector<ll> v;
        vector<ll> s;
        ll sum = 0;

        for (ll i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());

        for (ll i = n - 1; i >= 0; i--)
        {
            sum += v[i];
            s.push_back(sum);
        }

        while (q--)
        {
            ll y;
            cin >> y;

            ll ans = -1;
            for (ll i = 0; i < n; i++)
            {
                if (s[i] >= y)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}