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
        ll n, x;
        cin >> n >> x;
        vector<bool> prime(n + 1, true);
        int i, j;
        bool ans = true;

        ll l = n / 2 + 1;
        ll maxi = (n - l + 1) * l;

        // cout << maxi << endl;
        for (i = 2; i * i <= n; i++)
            if (prime[i])
                for (j = i * i; j <= n; j += i)
                    prime[j] = false;

        for (i = 2; i*i <= maxi; i++)
        {
            if (prime[i])
            {
                if (x % i)
                    ans = false;
            }
        }

        if (x > maxi)
        {
            cout << "NO\n";
        }
        else if (ans)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}