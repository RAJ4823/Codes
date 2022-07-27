#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        long long int n, m;
        cin >> n >> m;

        long long int a[n], fmax=0, smax=0;
        
        for (long long int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (long long int i = 0; i < n; i++)
        {
            if (fmax < a[i])
            {
                fmax = a[i];
            }
        }

        for (long long int i = 0; i < n; i++)
        {
            if (smax < a[i] && fmax != a[i])
            {
                smax = a[i];
            }
        }
        // cout << fmax << ' ' << smax << endl;
        long long diff = fmax - smax, r, ans = fmax*2;
        if (diff < m)
        {
            r = m - (diff % m);
        }
        else
        {
            r = diff % m;
        }

        long long int b = fmax + smax + r;
        cout << max(ans,b) << endl;
        // cout<< fmax<<endl<<smax<<endl;
    }
    return 0;
}