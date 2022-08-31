#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    while (n)
    {
        if (n & 1)
            ans++;
        n >>= 1;
    }
    cout << ans << endl;
    return 0;
}