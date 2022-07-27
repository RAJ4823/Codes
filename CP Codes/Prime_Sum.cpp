#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        if (a == 1 || b == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            ll A = max(a, b);
            ll B = min(a, b);
            ll x = __gcd(a, b);

            if(A%B == 0 || x != 1)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
    }
    return 0;
}