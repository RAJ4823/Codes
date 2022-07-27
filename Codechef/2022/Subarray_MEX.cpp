#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;

        if (k < x)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < n; i++)
                cout << i % x << " ";
            cout << endl;
        }
    }
    return 0;
}