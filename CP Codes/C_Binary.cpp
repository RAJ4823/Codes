#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int curr = 0, ans = n;
        int ones = 0, remz = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                remz++;
        }
        int zero = remz;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                remz--;
            else
                ones++;
            curr = max(ones, remz);
            ans = min(curr, ans);
        }
        remz = zero;
        ones = 0;
        for (int i = n - 1; i >= 0; i++)
        {
            if (s[i] == '0')
                remz--;
            else
                ones++;
            curr = max(ones, remz);
            ans = min(curr, ans);
        }
        cout << ans << endl;
    }
    return 0;
}