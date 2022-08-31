#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,x, count=1;

        cin>>n;
        cin>>x;

        int a[n], z=n-x;

        for(int i=0; i<n; ++i) cin>>a[i];
        
        for(int i=0; i<n-1; ++i)
        {
            if(a[i]!=a[i+1])
            count++;
        }

        cout<<min(count,z)<<"\n";
    }
    return 0;
}