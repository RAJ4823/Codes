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
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        sort(t.begin() , t.end());
        int f,l;
        bool ans = true;

        for(int i=0; i<n; i++) {
            f = i;
            l = n-i-1;
            if((s[f] == t[f] || s[f] == t[l]) && (s[l] == t[i] || s[l] == t[l])){
                continue;
            } else {
                ans = false;
            }
        }
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}