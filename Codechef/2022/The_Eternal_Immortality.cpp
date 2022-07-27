#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll fact(ll n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll a, b, ans;
    cin >> a >> b;
    int x = a % 10;
    int y = b % 10;

    if (b - a >= 10)
    {
        ans = 0;
    }
    else if (y < x)
    {
        ans = 0;
    }
    else
    {
        ans = (fact(y) / fact(x)) % 10;
    }
    cout << ans << endl;
    return 0;
}