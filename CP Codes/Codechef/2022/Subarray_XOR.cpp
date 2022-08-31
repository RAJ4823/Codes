#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll decimal(string s)
{
    ll w = 1, dec = 0;
    for (int i = s.length() - 1; i >= 0; i++)
    {
        dec += (s[i] - 48) * w;
        w = w * 2;
    }
    cout << dec << endl;
    return dec;
}

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

        string s;
        cin >> s;
        string rev;
        ll dec1, dec2, dec3;
        ll ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            rev.push_back(s[i]);
        }
        string curr;

        for (int i = 0; i < n; i++)
        {
            dec1 = (s[i] - 48);
            ans = ans ^ dec1;
            // cout << curr << " ";

            if (i < n - 1)
            {
                curr = s.substr(i, n - i);
                dec2 = decimal(curr);
                ans = ans ^ dec2;
                // cout << curr << " ";
            }
            if (i > 0 && i < n - 1)
            {
                curr = rev.substr(i - 1, n - i);
                dec3 = decimal(curr);
                ans = ans ^ dec3;
                // cout << curr << " ";
            }
        }
        cout << ans << endl;
    }
    return 0;
}