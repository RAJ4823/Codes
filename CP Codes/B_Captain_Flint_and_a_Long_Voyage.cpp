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
        ll n;
        cin >> n;
        ll x = (n+3)/4;
        ll y = n-x;

        while(y--)
            cout << 9;
        while(x--)
            cout << 8;
        cout << endl;

    }
    return 0;
}