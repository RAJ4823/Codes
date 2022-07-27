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

        int x;
        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            m[x]++;
        }

        int a = min(m[1], m[-1]);
        int b = max(m[1], m[-1]);
        // cout << a << ' ' << b << ' ' << y << endl;
        if (n % 2)
        {
            if (a == n / 2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
        else
        {
            if (a == b ||(a + 2 == b + b%2))
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
    return 0;
}