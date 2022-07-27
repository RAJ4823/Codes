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
        int n;
        cin >> n;

        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int ls = 0, rs = 0;
        ls = a[0];
        rs = a[n - 1];
        int ans = 0, count = 2;
        for (int i = 1; i < n; i++)
        {
            if(ls == rs)
            {
                ans = max(count,ans);
            }
            else
            {
                count++;
            }

            if (ls > rs)
            {
                rs+=a[n-i-1];
            }
            else if (ls < rs)
            {
                ls+=a[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}