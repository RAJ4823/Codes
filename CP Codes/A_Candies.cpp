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
        ll n, x = 0, ans = 0;
        cin >> n;

        int bits = log2(n)+1;
        for(int i=2; i<=bits; i++)
        {
            x = pow(2, i) - 1;
            if (n % x == 0)
            {
                ans = n / x;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}