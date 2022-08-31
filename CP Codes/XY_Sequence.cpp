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
        ll n, b, x, y;
        cin >> n >> b >> x >> y;
        ll sum = 0;
        ll a[n + 1];
        a[0] = 0;

        for (ll i = 1; i <= n; i++)
        {
            if (a[i - 1] + x <= b)
            {
                a[i] = a[i - 1] + x;
            }
            else
            {
                a[i] = a[i - 1] - y;
            }
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}