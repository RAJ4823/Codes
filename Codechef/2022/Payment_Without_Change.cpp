#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, n, s;
        cin >> a >> b >> n >> s;
        ll ans;
        ll x = s / n;
        if (x <= a)
            ans = x * n + b;
        else
            ans = a * n + b;

        if (ans >= s)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}