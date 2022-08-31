#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,k, x=0;
        int q[n], total=0;
        cin>>n>>k;

        string str;  
        cin>>str;

        for(int i=0;i<n;i++)
        {
            cin>>q[i];     
        }

        for(int i=0;i<n-1;i++)
        {
            if(str[i]==str[i+1])
            total+=2;
            if(str[i]!=str[i+1])
            total+=1;
        }

        for(int i=0; i<k; i++)
        {
            x = q[i]-1;

            if(str[x]=='1')
            str[x]='0';
            else
            str[x]='1';

            if(x==0)
            {
                if(str[x]==str[x+1]) total+=1;
                if(str[x]!=str[x+1]) total-=1;
            }
            else if(x==n-1)
            {
                if(str[x-1]==str[x]) total+=1;
                if(str[x-1]!=str[x]) total-=1;
            }
            else
            {
                if(str[x-1]==str[x] && str[x]==str[x+1]) total+=2;
                if(str[x-1]!=str[x] && str[x]!=str[x+1]) total-=2;
            }
            cout<<total<<endl;
        }
    }
    return 0;
}