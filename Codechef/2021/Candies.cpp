#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    int evensuf = 0, oddsuf = 0;
    int evenpre = 0, oddpre = 0;
    int arr[t], ans = 0;

    for(int i=0; i<t; i++)
    {
        cin>>arr[i];
        if(i & 1)  evensuf+= arr[i];
        else    oddsuf += arr[i];
    }

    for(int i=0; i<t; i++)
    {
        if(i & 1)  evensuf-= arr[i];
        else    oddsuf -= arr[i];

        if((evensuf + oddpre) == (evenpre + oddsuf))
        {
            ans++;
        }

        if(i & 1)  evenpre += arr[i];
        else    oddpre  += arr[i];
    }

    cout<<ans<<endl;
    return 0;
}