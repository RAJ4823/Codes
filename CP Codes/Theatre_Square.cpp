#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    ll n,m , a;
    cin >> n >> m >> a;
    ll x,y;
    if(n%a) {
        x = (n/a)+1;
    } else {
        x = (n/a);
    }

    if(m%a) {
        y = (m/a)+1;
    } else {
        y = (m/a);
    }
    cout << x*y << endl;
    return 0;
}