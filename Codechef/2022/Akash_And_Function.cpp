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
        ll count = 0;
        vector<bool> fun(n + 1, true);

        for (ll i = 2; i * i <= n; i++)
        {
            for (ll j = i; j <= n; j = j * 2)
            {
                // fun[j] = false;
                count++;
            }
        }
        if(n==2) {
            cout << "1\n";
        } else {

        cout << n - count << endl;
        }
    }
    return 0;
}
