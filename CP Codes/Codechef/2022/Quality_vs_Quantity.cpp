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
        ll n;
        cin >> n;

        ll a[n], sum[n];
        for(ll i=0; i<n; i++) {
            cin >> a[i];
        }

        sort(a, a+n);
        sum[0] = a[0];
        
        for(ll i=1; i<n; i++) {
            sum[i] = sum[i-1] + a[i];
        }

        ll sum1 = 0, sum2 = 0;
        bool ans = false;

        for(ll i=1; i<=(n/2); i++){
            sum1 = sum[i];
            sum2 = sum[n-1] - sum[n-i-1];

            if(sum2 > sum1) {
                ans = true;
                break;
            }
        }

        if(ans) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        
    }
    return 0;
}