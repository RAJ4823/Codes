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
        ll x;
        cin >> x;

        ll k = (x/2) + (x/3) + (x/4);
        
        if(x) {
            if(k>x)
            cout << k << endl;
            else 
            cout << x << endl;
        }
    }
    return 0;
}