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

        map<char, int> m;
        vector<int> v;

        int ans = 0, count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            m[s[i]]++;
            if (m[s[i]] == 2)
            {
                m[s[i]] = 0;
                ans += (count-1);
                count = 0;
            }
            else
            {
                count++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}