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
        ll n, s;
        cin >> n >> s;
        ll x= ((n*(n+1))/2) - s;
        
        if(x<=n && 0 < x) {
            cout << x << endl;
        }
        else {
            cout << -1 << endl;
        }
    }
    return 0;
}