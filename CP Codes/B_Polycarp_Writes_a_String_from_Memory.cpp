#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        string str = "";
        int count = 0, ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            vector<int> v(26, 1);
            count = 0;
            while (true)
            {
                count += v[s[i] - 97];
                if (count > 3 || i >= s.length())
                    break;
                v[s[i] - 97] = 0;
                i++;
            }
            i--;
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}