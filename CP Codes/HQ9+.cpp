#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    string s;
    cin >> s;
    bool ans = false;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'H' || s[i] == 'Q' || s[i] == '+' || s[i] == '9')
            ans = true;
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}