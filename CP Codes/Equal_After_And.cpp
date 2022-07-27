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
        ll n, ans = 0;
        cin >> n;
        ll a[n];
        cin >> a[0];
        ll mini = a[0];

        for (int i = 1; i < n; i++)
        {
            cin >> a[i];
            mini &= a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] == mini)
                continue;

            if (i == n - 1)
            {
                ans++;
                continue;
            }

            a[i + 1] &= a[i];
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}