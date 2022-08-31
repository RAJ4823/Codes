#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;
    int x[t] , y[t], z[t];
    int sx = 0, sy = 0, sz = 0;

    for(int i=0; i<t; i++) {
        cin >> x[i] >> y[i] >> z[i];
        sx += x[i];
        sy += y[i];
        sz += z[i];
    }
    if(sx || sy || sz) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
    return 0;
}