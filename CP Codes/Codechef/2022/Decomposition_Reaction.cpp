#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    ll a[n];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    while (m--)
    {
        int c, x;
        cin >> c >> x;

        while (x--)
        {
            int w, j;
            cin >> w >> j;
            ll ans = ((w % mod) * (a[c - 1] % mod)) % mod;
            a[j - 1] = (a[j - 1] % mod + ans) % mod;
        }
        a[c - 1] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}