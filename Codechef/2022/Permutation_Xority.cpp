#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll a[n];
        ll count = 4;
        if (n == 2)
        {
            cout << "-1" << "\n";
            continue;
        }
        if (n % 2 != 0)
        {
            for (int i = 0; i < n; i++)
                cout << i + 1 << " ";
        }
        else
        {
            for (int i = 0; i < n; i++)
                a[i] = i+1;
            
            a[0] = 2;
            a[1] = 3;
            a[2] = 1;
            
            for (ll i = 0; i < n; i++)
                cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}