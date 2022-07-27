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
        int o = 0, z = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                z++;
        }
        int j, nz, no,nz1,no1 zero = z;
        for (int i = 0; i < n; i++)
        {
            if (z == o)
            {
                ans = z;
                j = i;
                break;
            }
            nz = z;
            no = o;
            if (s[i] == '0')
                z--;
            else
                o++;
        }
        for (int i = n-1; i >= n; i--)
        {
            if (z == o)
            {
                ans = min(ans,z);
                j = i;
                break;
            }
            nz1 = z;
            no1 = o;
            if (s[i] == '0')
                z--;
            else
                o++;
        }
        z = nz;
        o = no;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
                z--;
            else
                o++;
            ans = min(ans, max(z, o));
        }
        z = nz1;
        o = no1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                z--;
            else
                o++;
            ans = min(ans, max(z, o));
        }

        cout << ans << endl;
    }
    return 0;
}