#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        map<int, bool> m;
        bool ans = true;

        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] + 1 == a[(i + 1) % n])
            {
                m[a[i]] = false;
                m[a[i + 1]] = false;
                i++;
            }
        }
        for (auto i : m)
        {
            if (i.second)
            {
                ans = false;
                break;
            }
        }
        if (ans || n == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}