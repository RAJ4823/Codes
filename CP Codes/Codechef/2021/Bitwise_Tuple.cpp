#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define MOD 1000000007
using namespace std;

ll power(ll base, ll n)
{
    ll ans = 1;
    
    while(n>0)
    {
        if(n%2) ans = (ans*base)%MOD;
        base = (base*base)%MOD;
        n/=2;
    }   
    return ans;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n,m;
        cin>>n>>m;

        ll N = power((ll)2,n)-1;
        ll ANS = power(N,m);

        cout<<ANS<<"\n";
    }
    return 0;
}