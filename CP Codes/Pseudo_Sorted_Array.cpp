#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                break;
            }
        }

        bool ans = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
                ans = false;
        }

        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}