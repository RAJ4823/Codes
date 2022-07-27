#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vector<int> v(26.0);
        for (int i = 0; i < s1.size(); i++)
            v[s1[i] - 'a']++;

        for (int i = 0; i < s2.size(); i++)
            v[s2[i] - 'a']--;

        int min = s2[0] - 'a';
        int ct = 1;
        for (int i = 1; i < s2.size(); i++)
        {
            if (s2[i] < s2[i - 1])
                ct = 0;
            if (s2[i] > s2[i - 1])
                break;
        }
        int pos = s2[0] - 'a' + ct;
        for (int i = 0; i < pos; i++)
        {
            while (v[i] > 0)
            {
                char x = i + 'a';
                cout << x;
                v[i]--;
            }
        }
        cout << s2;
        for (int i = pos; i < 26; i++)
        {
            while (v[i] > 0)
            {
                char x = i + 'a';
                cout << x;
                v[i]--;
            }
        }
        cout << endl;
    }
    return 0;
}
