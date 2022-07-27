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
        ll n, x;
        cin >> n >> x;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
    
        if (n >= x)
        {
            cout << n << endl;
        }
        else
        {
            sort(a, a + n);
            ll m = x / a[0];
            ll k = x / n;

            if (x % a[0])
                m++;    
            if (x % n)
                k++;
            cout << max(m,n) << endl;
        }
    }
    return 0;
}