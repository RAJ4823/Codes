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
        string s;
        cin >> s;

        int ans = 1, z = 0;
        bool one = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '1')
                one = true;
            if (s[i] == '1' && s[i + 1] == '1')
            {
                ans++;
            }
            if (s[i] == '1' && s[i + 1] == '0')
            {
                z++;
            }
        }
        if (one)
            cout << max(1,min(ans/2, ans-z)) << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}