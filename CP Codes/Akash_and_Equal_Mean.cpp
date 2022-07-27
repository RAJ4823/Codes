#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n], sum = 0;
        map<ll, ll> m;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            m[a[i]]++;
        }
        ll k, ans = 0;
        
        if ((sum * 2) % n == 0)
        {
            sum = (sum * 2) / n;
            for (int i = 0; i < n; i++)
            {
                k = sum - a[i];
                m[a[i]]--;
                ans += m[k];
            }
        }
        cout << ans << endl;
    }
    return 0;
}