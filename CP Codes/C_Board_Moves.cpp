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
        ll x = (n - 1) / 2;
        ll ans = (x * (x + 1) * (2 * x + 1)) / 6;
        cout << ans * 8 << endl;
    }
    return 0;
}