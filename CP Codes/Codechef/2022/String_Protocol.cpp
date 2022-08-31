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
        string s;
        cin >> n;
        cin >> s;
        int count = 0;

        for(int i=0; i<n; i++) {
            if(s[i+1] == s[i]) {
                count++;
                i++;
            } else {
                count++;
            }
        }
        cout << count << endl;
        
    }
    return 0;
}