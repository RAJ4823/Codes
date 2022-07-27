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
        int n = s.length();
        int count = 0;
        int ans = 0;

        for(int i=1; i<n-1; i++) {
            if(s[i] == s[0] || s[n-1] == s[i]) {
                count = 0;
            } else {
                count++;
            }
                ans = max(ans, count);
        }
        if(ans)
        cout << ans << endl;
        else
        cout << "-1\n";
    }
    return 0;
}