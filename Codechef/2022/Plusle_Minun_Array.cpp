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
        int n;
        cin >> n;

        ll a[n];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] = abs(a[i]);
            // cout << a[i];
        }

        ll mxi = 1;
        ll mni = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] > a[mxi] && i % 2)
                mxi = i;

            if (a[i] < a[mni] && (i + 1) % 2)
                mni = i;
        }

        if (a[mxi] > a[mni])
        {
            ll temp = a[mni];
            a[mni] = a[mxi];
            a[mxi] = temp;
        }

        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2)
            {
                sum -= a[i];
            }
            else
            {
                sum += a[i];
            }
        }
        cout << sum << endl;
    }
    return 0;
}