#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll t;
    cin >> t;

    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        if (n % 2)
        {
            cout << x << ' ';
            for (ll i = 0; i < n / 2; i++)
            {
                cout << x + i + 1 << ' ';
                cout << x - i - 1 << ' ';
            }
            cout << endl;
        }
        else
        {
            cout << x - 1 << ' ';
            cout << x + 1 << ' ';
            for (ll i = 0; i < n / 2 - 1; i++)
            {
                cout << x + i + 2 << ' ';
                cout << x - i - 2 << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}