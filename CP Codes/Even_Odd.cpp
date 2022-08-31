#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll k,n;
    cin >> n >> k;
    ll i = (n+1)/2;
    ll ans;
    
    if(k <= i)
        ans = k*2 - 1;
    else
        ans = (k-i)*2;
    cout << ans << endl;
    
    return 0;
}