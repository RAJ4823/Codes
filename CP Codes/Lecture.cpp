#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    map <string, string> mp;
    string s1, s2;

    while(m--) {
        cin >> s1 >> s2;
        if(s1.length() <= s2.length()) {
            mp[s1] = s1;
        } else {
            mp[s1] = s2;
        }
    }
    string s;
    vector<string> v;
    for(int i=0; i<n; i++) {
        cin >> s;
        cout << mp[s] << " ";
    }
    
    return 0;
}