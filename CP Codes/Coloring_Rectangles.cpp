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
        int n, m;
        cin >> n >> m;
        int x, y, z, X, Y, Z, ans, ANS;

        x = max(n, m);
        y = min(n, m);
        z = y * (x / 3);
        x -= (x / 3) * 3;

        X = max(x, y);
        Y = min(x, y);
        Z = Y * (X / 3);
        X -= (X / 3) * 3;

        ANS = min(X, Y) * ((max(X, Y) + 2) / 3) + Z;
        ans = ANS + z;

        cout << ans << endl;
    }
    return 0;
}