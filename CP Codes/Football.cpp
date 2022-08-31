#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;
    ll maxi = 0;
    string ans;

        map<string, int> m;
    while(t--)
    {
        string s;
        cin >> s;
        m[s]++;
    }
    for(auto i:m) {
        if(i.second > maxi) {
            maxi = i.second;
            ans = i.first;
        }
    }
    cout << ans << endl;
    return 0;
}