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
        int diff = 0, ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        for (int i = 0; i < n; i++)
        {
            for (int k = i + 1; k < n; k++)
            {
                for (int j = 0; j < m; j++)
                {
                    int a = v[i][j];
                    int b = v[k][j];
                    diff += abs(a - b);
                }
                ans = min(ans, diff);
                diff = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}