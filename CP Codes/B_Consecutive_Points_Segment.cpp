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
        int od = 0, nd = 0, x;
        bool ans = true;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            nd = a[i + 1] - a[i];
            if (nd == 1)
            {
                if (i == 0)
                    a[i + 1]++;
            }
            else if (nd == 2)
            {
                if (i == 0)
                    a[i]++;
                else
                    a[i + 1]--;
            }
            else if (nd == 3 && i == 0)
            {
                a[i]++;
                a[i + 1]--;
            }
            else if (nd == 0)
            {
                a[i + 1]++;
            }
            else
            {
                ans = false;
                break;
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     nd = a[i + 1] - a[i];
        //     if (nd != 1)
        //         ans = false;
        // }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}