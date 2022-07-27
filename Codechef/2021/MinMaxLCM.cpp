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
        ll x,k;
        cin >> x >> k;
        k=x*k;

        cout << x*2 << " " << (k-1)*k << endl;
        
    }
    return 0;
}