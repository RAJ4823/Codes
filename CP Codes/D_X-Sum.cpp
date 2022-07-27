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
        ll n, m;
        cin >> n >> m;

        ll a[n][m];
        for (ll i = 0; i < n; i++)
            for (ll j = 0; j < m; j++)
                cin >> a[i][j];

        ll ans[n][m], sum = 0, count = 0, x, y;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                // for top right
                for (ll k = 1; k < min(n, m); k++)
                {
                    if ((i + k) >= n || (j - k) < 0)
                        break;

                    sum += a[i + k][j - k]; 
                }

                // for bottom right
                for (ll k = 1; k < min(n, m); k++)
                {
                    if ((i + k) >= n || (j + k) >= m)
                        break;

                    sum += a[i + k][j + k];
                }

                // for bottom left
                for (ll k = 1; k < min(n, m); k++)
                {
                    if ((i - k) < 0 || (j + k) >= m)
                        break;

                    sum += a[i - k][j + k];
                }

                // fot top left
                for (ll k = 1; k < min(n, m); k++)
                {
                    if ((i - k) < 0 || (j - k) < 0)
                        break;

                    sum += a[i - k][j - k];
                }
                count = max(count, sum + a[i][j]);
                sum = 0;
            }
        }
        cout << count << endl;
    }
    return 0;
}
