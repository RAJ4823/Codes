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
        ll n;
        cin>>n;

        if(n%2==0)
        {
            cout<<n/2<<endl;
        }
        else
        {
            if(n==1)
            cout<<'1'<<endl;
            else
            cout<<n/2 +1<<endl;
        }
    }
    return 0;
}