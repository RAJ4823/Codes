#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, diff, a, flag = 0, count = 0;
        ll o = 0, z = 0;

        cin >> n;
        string s;
        cin >> s;
        bool ans;
        ll j = 1, e = n;

        for (ll int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                z++;
            else
                o++;
        }

        if (n % 2 != 0)
        {
            ans = false;
        }
        else
        {
            if (o == z)
            {
               ans = true;
            }
            else
            {
                char ch;
                diff = abs(z - o);
                a = diff / 2;

                if (o > z)
                    ch = '1';
                else
                    ch = '0';

                for (ll int i = 0; i < n; i++)
                {
                    if (s[i] == ch)
                    {
                        if (count == 0)
                            j = i+1;
                        count++;
                    }
                    else
                        count = 0;

                    if (count == a)
                    {
                        e = i + 1;
                        ans = true;
                        break;
                    }
                }
            }
        }
        if (ans)
        {
            cout << "YES\n";
            cout << j << " " << e << endl;
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}