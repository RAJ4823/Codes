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
        ll a[n];

        for (ll i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        ll diff1, diff2;
        bool ans = true;
        for (ll i = 1; i < n - 1; i++)
        {
            diff1 = a[i] - a[i - 1];
            diff2 = a[i + 1] - a[i];
            if (diff1 * 2 == diff2 || diff2 * 2 == diff1)
                continue;
            else
            {
                ans = false;
                break;
            }
        }
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}