#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long int

int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    ll t,n,m;
	cin>>t;

    while(t--)
    {
        cin>>n>>m;
        ll ans=0;

        vector<ll> mod(n+1,1);

        for(ll i=2;i<=n;i++){

            ll a=m%i;
            ans+=mod[a];

            for(ll j=a;j<=n;j+=i)
            {
                mod[j]++;
            }
        }
        cout<<ans<<endl;    
    }
	return 0;
}