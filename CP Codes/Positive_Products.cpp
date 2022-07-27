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
        ll n, temp;
        ll lz = 0, gz = 0;
        cin >> n;

        for (ll i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp > 0)
                gz++;
            if (temp < 0)
                lz++;
        }
        ll ans = ((gz * (gz - 1)) + (lz * (lz - 1)))/2;
        cout << ans << endl;
    }
    return 0;
}