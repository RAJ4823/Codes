#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    string s;
    cin >> s;
    int j =0, count = 0;
    string hello = "hello";

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == hello[j]) {
            count++;
            j++;
        }
    }
    if (count == 5)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}