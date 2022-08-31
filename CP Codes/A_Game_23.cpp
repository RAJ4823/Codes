#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans(ll n, ll m)
{
    ll x = m / n;
    ll count = 0;
    if (m % n)
        return -1;

    while (x != 1)
    {
        if (x % 3 == 0)
        {
            x /= 3;
            count++;
        }
        else if (x % 2 == 0)
        {
            x /= 2;
            count++;
        }
        else
        {
            return -1;
        }
    }
    return count;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    cout << ans(n, m) << endl;

    return 0;
}