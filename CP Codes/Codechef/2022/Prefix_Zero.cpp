#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        string s;
        cin >> s;

        int d1[n], d2[n], arr[n];
        int moves[n], sum = 0;

        for (i = 0; i < n; i++)
            arr[i] = s[i] - 48;

        for (i = 0; i < n; i++)
            d1[i] = 10 - arr[i];

        if (arr[0] == 0)
        {
            d2[0] = 10;
            moves[0] = 0;
        }
        else
        {
            d2[0] = arr[0];
            moves[0] = arr[0];
        }

        for (i = 1; i < n; i++)
        {
            if (d1[i - 1] >= d1[i])
                d2[i] = d1[i - 1] - d1[i];
            else
                d2[i] = d1[i - 1] - d1[i] + 10;

            sum += d2[i];
            moves[i] = sum;
        }

        for (i = 0; i < n; i++)
            cout << d2[i] << " ";

        int ans = 0;
        for (i = 0; i < n; i++)
        {
            if (moves[i] < k)
                ans++;
            else
                break;
        }
        cout << ans << endl;
    }
    return 0;
}