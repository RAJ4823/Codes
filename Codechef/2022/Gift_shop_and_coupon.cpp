#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        
        ll arr[n], mx = 0;

        for (ll i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);

        ll sum = 0, ans = 0, x;

        for (ll i = 0; i < n; i++)
        {
            sum += arr[i];
            if (sum > k)
            {
                x = (arr[i] + 1) / 2;
                sum -= arr[i];
                sum += x;
                if (sum <= k)
                    ans++;
                else
                    break;
            }
            else
                ans++;
        }

        cout << ans << endl;
    }
    return 0;
}