#include <bits/stdc++.h>
#define X 1e5
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, mini = X, maxi = 0;
        cin>>n;
        int arr[n];
        int li = 0; //index of lowest power stone
        int hi = 0; //index of highest power stone
        int diff = 0; 

        for(int i=0; i<n; ++i)
        {
            cin>>arr[i];

            if(arr[i]>=maxi)
            {
                maxi = arr[i];
                hi = i+1;
            }
            if(arr[i]<=mini)
            {
                mini = arr[i];
                li = i+1;
            }
        }
        diff = abs(li - hi);  //positive difference btwn li & hi
        li = min(li, n-li+1); // (n-li+1) = distance from right side
        hi = min(hi, n-hi+1); // simillar for (n-hi+1)
    
        if(diff<=max(li , hi))
            cout<<(diff + min(li, hi))<<"\n";
        else
            cout<<(li + hi)<<"\n";      
    }
    return 0;
}