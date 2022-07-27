#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n, count = 0;
    cin>>n;

    int h,m;
    int arr[n];

    for(int i=0;i<n; ++i)
    {
        cin>>h>>m;
        arr[i] = h*60 + m;
    }
    sort(arr, arr+n);
    int temp = arr[0];
    int x,y=1;

    for(int i=0; i<n-1; ++i)
    {
        if(arr[i+1]==arr[i])
        {
            count++;
            y=max(y,count+1);
        }
        else
        {
            count=0;
        }
      
    }
    cout<<y<<"\n";
   
    return 0;
}