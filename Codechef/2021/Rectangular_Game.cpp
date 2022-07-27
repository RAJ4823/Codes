#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n= 0;
    cin >> n;
    ll sum =n;
    ll mx = 0;
    
    for(ll i=n-1; i>1; i--)
    {
        if(n%i==0)
        {
            sum += i;
            n = i;
        }
    }
    cout<<sum+1<<"\n";

    return 0;
}