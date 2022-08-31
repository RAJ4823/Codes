#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin >> n;

        if(n==1) cout << 3 << endl;
        else {
            cout<<1;
            for(int i=2; i<n; ++i) {
                cout << 0;
            }
            cout << 5 << endl;
            
        }
        // ll n, ans = 0, digit = 0;
        // cin >> n;
        // ans = n;
        // ll min = pow(10,n-1);
        // ll max = pow(10,n);

        // for(ll i=min; i<max; i++) {
        //     if(i%2==0)
        //     continue;

        //     if(i%3==0 && i%9!=0) {
        //         ans = i;
        //         break;
        //     }
        // }
        // cout << ans << endl;
    }
    return 0;
}