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
        int ans = (n + 1) / 2;
        if (n % 2)
            ans = (0 - ans);
        cout << ans << endl;
    }
    return 0;
}