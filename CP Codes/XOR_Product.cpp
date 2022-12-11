#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define MOD 998244353ll

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> even;
        ll ans = 1, ones = 0;

        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;

            if (x % 2 == 0)
                even.push_back(x);
            else
                ans = ((ans % MOD) * (x % MOD)) % MOD;

            if (x == 1)
                ones++;
        }

        sort(even.begin(), even.end());

        int i = 0;
        while (ones > 0 && i < even.size())
        {
            ones--;
            even[i]++;
            ans = ((ans % MOD) * (even[i] % MOD)) % MOD;
            i++;
        }
        while (i < even.size())
        {
            ans = ((ans % MOD) * (even[i] % MOD)) % MOD;
            i++;
        }
        cout << ans << endl;
    }
    return 0;
}