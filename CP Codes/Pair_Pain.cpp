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
        ll n;
        cin >> n;

        ll x, one = 0, two = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x == 1)
                one++;
            if (x == 2)
                two++;
        }
        ll ans = 0, ans2 = 0;
        // n--;

        // if (two > 1)
        //     two = (two - 1) * (two - 2) + 1;
        // else
        //     two = 0;

        for (int i = 1; i <= two; i++)
            ans2 += (two - i);
        for (int i = 1; i <= one; i++)
            ans += (n - i);

        cout << ans + ans2 << endl;
    }
    return 0;
}