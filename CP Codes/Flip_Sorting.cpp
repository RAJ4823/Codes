#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool isSort(string s)
{
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
            count++;
        else
            break;
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
            count++;
        else
            break;
    }
    if (count == s.length())
        return true;
    else
        return false;
}

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
        vector<pair<int, int>> v;

        while (!isSort(s))
        {
            int start = 0, end = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == '0')
                {
                    start = i;
                    break;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (s[n - i - 1] == '0')
                {
                    end = (n - i - 1);
                    break;
                }
            }
            for (int i = start; i <= end; i++)
            {
                if (s[i] == '0')
                    s[i] = '1';
                else
                    s[i] = '0';
            }
            v.push_back(make_pair(start+1, end+1));
        }

        cout << v.size() << endl;
        for (auto i : v)
            cout << i.first << ' ' << (i.second-i.first+1) << endl;
    }

    return 0;
}