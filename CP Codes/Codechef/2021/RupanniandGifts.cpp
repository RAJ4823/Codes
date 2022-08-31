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
        int n, happy = 0, k=0, sum=1;
        cin>>n;
        int arr[n], nw[n];
        int all[9]={1,2,3,4,5,6,7,8,9};

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        sort(arr, arr+n);

        for(int i=1; i<n; i++)
        {
            if(arr[i-1]==arr[i])
            {
                happy=1;
            }
            else
            {
                nw[k]=arr[i-1];
                k++;
            }
        }

        for(int i=0; i<k; i++)
        {
            for(int j=0; j<n;j++)
            {
                if(nw[i]==all[j])
                {
                    sum++;
                }
            }
        }

        if(sum==n && happy==0)
        {
            cout<<"HAPPY"<<endl;
        }
        else
        {
            cout<<"ANGRY"<<endl;
        }

  
    }
    return 0;
}