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
        ll x = n;
        ll ans = n + 1;
        ll nine = 0;
        // bool nine = true;
        while(x!=0)
        {
            if(x%10 == 9)
                nine++;
            else
                break;
            x/=10;
        }

        if(ans%10 == 0 && nine%2 == 0)
            ans--;
        if (n % 10 == 9)
            ans++;
        cout << ans << endl;
    }
    return 0;
}