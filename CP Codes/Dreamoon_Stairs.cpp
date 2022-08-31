#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    int x, y, ans;

    x = (n + 1) / 2;
    y = (x / m);
    if (x % m)
        ans = y * m + m;
    else
        ans = y * m;

    if (n < m)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}