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
        ll n, k;
        cin >> n >> k;
        ll ans = 0, x, y;

        if (k >= n)
        {
            ans = k / n;
            if (k % n)
                ans++;
        }
        else
        {
            if(n%k == 0)
            ans = 1;
            else
            ans = 2;
        }
        cout << ans << endl;
    }
    return 0;
}