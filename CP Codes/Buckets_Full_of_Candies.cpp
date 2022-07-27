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
        ll n, m, l;
        cin >> n >> m >> l;

        ll x = m % (n + l - 1);

        if (x >= l && x <= (n + l - 2))
            cout << 0 << endl;
        else
            cout << x << endl;
    }
    return 0;
}