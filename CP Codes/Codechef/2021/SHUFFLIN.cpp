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
        int n,x = 0,y=0, ans =0;
        cin >> n;
        ll a[n];

        for(int i=0; i<n; ++i) {
            cin >> a[i];

            if(a[i]%2==0) x++;
        }

        if(n%2==0) {
            ans = ((3*n)/2) - x;
        }
        else {
            if(x > (n-x))
            ans = ((3*n+1)/2) - x;
            else 
            ans = ((3*n-1)/2) - n + x;
        }

        cout << ans << endl;
    }
    return 0;
}