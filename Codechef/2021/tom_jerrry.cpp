#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int diff(int a,int b)
{
    if(a>b)
    return (a-b);
    else
    return (b-a);
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int a,b,c,d,k, dif;
        cin>>a>>b>>c>>d>>k;

        dif = diff(a,c)+ diff(b,d);

        if((dif ==k) || ((k-dif)%2==0 && k>dif))
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    return 0;
}