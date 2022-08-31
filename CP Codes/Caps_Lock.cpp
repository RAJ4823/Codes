#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    string s;
    cin >> s;
    bool t = true;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            continue;
        else
            t = false;
    }

    if (t)
    {
        if(s[0] >= 'A' && s[0] <= 'Z')
            s[0] = tolower(s[0]);
        else
            s[0] = toupper(s[0]);
            
        for (int i = 1; i < s.length(); i++)
            s[i] = tolower(s[i]);
    }
    cout << s << endl;

    return 0;
}