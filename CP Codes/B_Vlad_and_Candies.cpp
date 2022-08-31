#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll diff(ll a, ll b)
{
    if (a - b < 2)
        return true;
    return false;
}

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
        ll x;
        vector<ll> a;

        for (int i = 0; i < n; i++)
        {
            cin >> x;
            a.push_back(x);
        }

        sort(a.begin(), a.end());
        bool ans = true;
        vector<bool> m;

        if (a[0] != 1 && n == 1)
            ans = false;

        for (int i = n - 1; i > 0; i--)
        {
            if (diff(a[i], a[i - 1]))
            {
                a[i - 1] = a[i - 2];
            }
            else
            {
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}