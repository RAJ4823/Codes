#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(ll a[], ll a1, ll b1)
{
    if (a[3] == a1 * b1 && a[2] == a1 + b1)
    {
        if (a1 / b1 == a[0] && a1 - b1 == a[1])
            return true;
        else if (a1 / b1 == a[1] && a1 - b1 == a[0])
            return true;
    }
    else if (a[2] == a1 * b1 && a[3] == a1 + b1)
    {
        if (a1 / b1 == a[0] && a1 - b1 == a[1])
            return true;
        else if (a1 / b1 == a[1] && a1 - b1 == a[0])
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll a[4];
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        sort(a, a + 4);

        ll x, y, A, B, d;
        x = a[3];
        y = a[2];
        d = y * y - 4 * x;

        if (d >= 0)
        {
            ll a1, a2, b1, b2;
            d = sqrt(d);

            a1 = (y + d) / 2;
            b1 = x / a1;
            a2 = (y - d) / 2;
            b2 = x / a2;

            if (check(a, a1, b1))
            {
                cout << a1 << ' ' << b1 << endl;
                continue;
            }
            if (check(a, a2, b2))
            {
                cout << a2 << ' ' << b2 << endl;
                continue;
            }
        }
        cout << "-1 -1" << endl;

        // pow(a,2) - a*y + x = 0;
    }
    return 0;
}