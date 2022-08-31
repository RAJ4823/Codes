#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin >>s;

        if(s.length()%2 == 0 && s[0] != ')' && s[s.length()-1] != '(')
            cout << "YES\n";
        else    
            cout << "NO\n";
    }
    return 0;
}