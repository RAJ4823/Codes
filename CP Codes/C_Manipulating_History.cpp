#include <bits/stdc++.h>
// #define int long long;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n = 2 * n;
        unordered_map<int, int> m;
        string a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        string cnt;
        cin >> cnt;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a[i].length(); j++)
            {
                m[a[i][j] - 'a']++;
            }
        }
        for (int i = 0; i < cnt.length(); i++)
        {
            m[cnt[i] - 'a']++;
        }
        char ans;
        for (int i = 0; i < 26; i++)
        {
            if (m[i] % 2 != 0)
            {
                ans = i;
                break;
            }
        }
        cout << (char)(ans + 'a') << endl;
    }

    return 0;
}