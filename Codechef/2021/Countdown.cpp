#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--)
    {
        int n, ans = 0;
        cin >> n;
        string s;
        cin >> s;
        
        for(int i=0; i<n; ++i) {
            ans += s[i]-48;
            if(s[i]!='0' && i!=n-1)
            ans++;
        }
        cout << ans << endl;
        
    }
    return 0;
}