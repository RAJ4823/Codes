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
        int n, a, b, c, z;
        cin >> n >> a >> b >> c;
        int y = min(a, min(b,c));
        if(y == a)
            z = min(b,c);
        if(y == b)
            z = min(a,c);
        if(y == c)
            z = min(a,b);

        int ans = (n-1)*y + z;
        cout << ans << endl;
    }
    return 0;
}