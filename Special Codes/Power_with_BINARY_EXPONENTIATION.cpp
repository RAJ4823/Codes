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
    cout<<ans<<"\n";

    return 0;
 }
 
 int main()
 {
     ll n;
     ll base;
     cout<<"Enter base : ";
     cin>>base;
     cout<<"Enter power : ";
     cin>>n;

     power(base,n);
 }