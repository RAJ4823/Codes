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
        for(int i=0; i<n; i++)
           cin >> a[i];
        map<int, int> m;
        int x, ans = 0;
        bool f = false;

        for (int i = 0; i < n; i++)
        {
            m[a[i]]++;
            if (m[a[i]] > 2)
            {
                ans = a[i];
                f = true;
                break;
            }
        }
        if (f)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}