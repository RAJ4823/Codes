#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"

ll calc(ll x, ll y)
{
    // a = min(a, b);
    // b = max(a, b);
    ll a = min(x, y);
    ll b = max(x, y);

    ll ans = b, diff = b - a;

    while (diff > a)
    {
        a <<= 1;
        ans++;
        diff = b - a;
    }

    if (a != b)
        ans++;

    return ans;
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        if (a == b)
            cout << a << endl;
        else if (a == 0 || b == 0)
            cout << "-1\n";
        else
            cout << calc(a, b) << endl;
    }
    return 0;
}