#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        if (k == 1)
        {
            if (n == 1)
            {
                cout << 1 << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
        else if (n == k)
        {
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
        }
        else
        {
            int s = n - k;
            cout << 1 << " ";
            for (int i = 3; i <= n; i++)
            {
                cout << i << " ";
                if (i == s + 2)
                    cout << 2 << " ";
            }
            cout << endl;
        }
    }
    return 0;
}