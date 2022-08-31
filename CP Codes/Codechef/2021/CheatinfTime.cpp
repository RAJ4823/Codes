#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        ll n,k,f;
        cin>>n>>k>>f;
        ll start[n], end[n];

        for(int i=0;i<n;i++)
        {
            cin>>start[i]>>end[i];
        }

        sort(start, start+n);
        sort(end, end + n);

        ll ans=0, i, zero =0;
        ll max_end=end[0];

        for(i=1; i<n;i++)
        {
            ans+= max(zero,start[i]-max_end);
            max_end=max(max_end, end[i]);
        }

        ans+=start[0];
        ans+=f-max_end;

        if(ans>=k)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}