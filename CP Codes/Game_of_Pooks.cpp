#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        if (n == 2 || n == 3)
            cout << n - 1 << endl;
        else
            cout << n << endl;
    }
    return 0;
}
