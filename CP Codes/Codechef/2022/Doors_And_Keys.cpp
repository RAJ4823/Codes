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
        cin >> s;
        map<char,bool> m;
        bool ans = true;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'r' || s[i] == 'b' || s[i] == 'g') {
                m[s[i]] = true;
            } else {
                char c = s[i] + 32;
                if(m[c]){
                    continue;
                } else {
                    ans = false;
                    break;
                }
            }
        }

        if(ans)
            cout << "YES\n";
        else
            cout <<"NO\n";
    }
    return 0;
}