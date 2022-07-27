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
        int n, m;
        cin >> n >> m;

        vector<string> v;
        string s;
        
        int max_index = 0, curr_index = m;
        bool found = true, ans = true;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            v.push_back(s);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (v[i][j] == 'R')
                {
                    if (found)
                    {
                        max_index = j;
                        found = false;
                        break;
                    }
                    else
                    {
                        curr_index = j;
                        break;
                    }
                }
            }
            if (curr_index < max_index)
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