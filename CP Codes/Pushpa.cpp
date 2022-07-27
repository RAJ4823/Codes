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
        ll max_count = 0, j, max_element = 0;
        ll calc;
        //j = max_count element

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
            calc = (a[i] + m[a[i]] - 1);
            if (calc > max_count)
                max_count = calc;
            if (a[i] > max_element)
                max_element = a[i];
        }

        cout << max(max_count, max_element) << endl;
    }
    return 0;
}