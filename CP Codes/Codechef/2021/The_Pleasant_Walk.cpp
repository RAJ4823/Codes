#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n, k;
    cin >>n >>k;

    ll arr[n];
    for(int i=0; i<n; ++i)  cin>>arr[i];

    ll sum=1, ans =1;

    for(int j=0; j<n-1; ++j)
    {
        if(arr[j] != arr[j+1])
        {
            sum++;
            ans = max(sum, ans);
        }
        else
        {
            sum =1;
        }
    }

    cout << ans << endl;
    return 0;
}