#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n, m;
    cin >> n >> m;
    ll a[m];
    ll minus = 1;
    ll sum = 0;

    for (ll i = 0; i < m; i++)
    {
        cin >> a[i];
        if (a[i] < minus)
        {
            sum += (n - minus + a[i]);
        }
        else
        {
            sum += (a[i] - minus);
        }
        minus = a[i];
    }

    cout << sum << endl;
    return 0;
}