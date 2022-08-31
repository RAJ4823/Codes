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
        ll x,y;
        ll a,b;
        cin >> x >> y;
        cin >> a >> b;
        
        ll ans1 = min(x,y)*b + (max(x,y) - min(x,y))*a;
        ll ans2 = (x+y)*a;

        cout << min(ans1, ans2) << endl;
    }
    return 0;
}