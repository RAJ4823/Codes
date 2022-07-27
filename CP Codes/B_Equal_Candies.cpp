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
        ll a[n];
        for(ll i=0; i<n; i++)
            cin >> a[i];
        ll mini = a[0];
        for(ll i=0; i<n; i++)
        {
            if(a[i] < mini)
                mini = a[i];
        }
        ll sum = 0;
        for(ll i=0; i<n; i++)
        {
            sum += (a[i]-mini);
        }
        cout << sum << endl;
        
    }
    return 0;
}