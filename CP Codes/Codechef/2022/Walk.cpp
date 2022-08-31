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
        int n, count = 0;
        cin >> n;
        int a[n], maxi = n - 1;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] > a[maxi])
                maxi = i;
        }
        cout << a[maxi] + maxi << endl;
    }
    return 0;
}