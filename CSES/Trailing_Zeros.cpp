#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    ll m = log10(n + 1) / log10(5);
    for (ll i = 1; i <= m; i++)
        ans += (n / pow(5, i));

    cout << ans << endl;
    return 0;
}