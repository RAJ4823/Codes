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
        int n;
        string s;
        cin >> n;
        cin >> s;

        for(int i=0; i<n; ++i){
        
            if(s[i]=='U')
            cout << 'D';
            else if(s[i]=='D')
            cout << 'U';
            else
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}