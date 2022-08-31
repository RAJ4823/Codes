#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int n, win =0, x=1, y=2, z=0;
    cin>>n;

    while(n--)
    {
        cin>>z;

        if(win==1)
        continue;

        if(z==x || z==y)
        {
            y = 6-x-y;
            x = z;
        }
        else
        {
            win = 1;
        }
    }
    
    if(win==0)
    cout<<"YES\n";
    else
    cout<<"NO\n";
    return 0;
}