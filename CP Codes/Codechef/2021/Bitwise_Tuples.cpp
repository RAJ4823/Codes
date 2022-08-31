#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,m, sum= 0;
        cin>>n>>m;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; i++)
            {
                if(i&j==0)
                {
                    cout<<i<<" "<<j<<endl;
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}