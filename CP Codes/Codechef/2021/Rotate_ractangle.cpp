#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    ll w[n], h[n];
    int count = 0;

    for(int i=0; i<n; ++i)
    {
        int x,y;
        cin >> x >> y;
        w[i] = min(x,y);
        h[i] = max(x,y);
    }

    for(int  i=0; i<n-1; i++)
    {
        if(h[i]>=h[i+1])
        {
            count++;
        }
        else
        {
            swap(w[i+1],h[i+1]);
            if(h[i]>= h[i+1])
            {
                count++;
            }
        }
    }

    if(count+1 == n)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}