#include <bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;

ll power(ll base, ll n)
{
    ll ans = 1;

    while (n > 0)
    {
        if (n % 2)
            ans = (ans * base) % MOD;
        base = (base * base) % MOD;

        n /= 2;
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll x, n;
        cin >> n;
        ll ans = 1;
        if (n % 2 == 0)
        {
            for (ll i = 1; i <= n / 2; i++)
            {
                ans = ((ans % MOD) * power(i, 2) % MOD) % MOD;
            }
            cout << ans << endl;
        }
        else
            cout << "0\n";
    }
    return 0;
}