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
        string s;
        cin >> s;
        int count = 0;
        bool ans = true;
        int i = 0;
        while (i != s.length())
        {
            if (s[i] == 'a')
            {
                while (s[i] != 'b' && i < s.length())
                {
                    count++;
                    i++;
                }
            }
            else
            {
                while (s[i] != 'a' && i < s.length())
                {
                    count++;
                    i++;
                }
            }
            if (count > 1)
                count = 0;
            else
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}