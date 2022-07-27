#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (log2(n) != (int)log2(n) && n % 2 == 0)
        {
            ll x = n;
            while(x%2 != 1)
            {
                x/=2;
            }
            x*=2;
            cout << 0 << ' ' << (n/x) << ' ' << (x/2 - 1)*(n/x) << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}
