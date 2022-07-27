#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, t=0;
    cin >> n;
    vector<ll> v;

    for(ll i=0; i<n; ++i)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(), v.end());

    if(n == 1)
    {
        if(v[0]==1)     cout<<"YES\n";
        else            cout<< "NO\n";

    }
    else if(v[0]==0)
    {
        if(v[1]==0)     cout<< "NO\n";
        else            cout<< "YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}