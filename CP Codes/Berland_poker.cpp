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
        int n, m, k;
        cin >> n >> m >> k;

        int x, y, z;
        if (m <= n / k)
        {
            x = m;
            y = 0;
        }
        else
        {
            x = n / k;
            z = m - x;
            k--;
            y = z/k;
            if(z%k)
                y++;
        }

        cout << (x - y) << endl;
    }
    return 0;
}