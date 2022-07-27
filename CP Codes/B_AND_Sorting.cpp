#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define SIZE 1000001
#define MOD 1000000007LL

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ans = -1;
        f(i, n)
        {
            if (a[a[i]] != a[i])
            {
                ans &= a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
