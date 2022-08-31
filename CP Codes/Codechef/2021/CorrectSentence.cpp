#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int check(string k)
{
    int l;
    if((int)k[0]>=97 && (int)k[0]<=109)
    l=1;
    else if((int)k[0]>=78 && (int)k[0]<=90)
    l=0;
    else
    cout<<"NO\n";

    for(int i=1; i<k.size; i++)
    {
        if(k[i])
    }
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int k;
        cin>>k;
        string lan[k];
        
        for(int i=0; i<k; i++)
        {
            cin>>lan[i];
        }

        for(int i=0; i<k; i++)
        {
            check(lan[i],k)
        }
    }
    return 0;
}