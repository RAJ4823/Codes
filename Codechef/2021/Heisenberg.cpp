#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        int i,j;
        ll n;
        cin>>n;
        vector<bool> prime(n+1, true);

        for(i=2; i*i<=n; i++) {
            
            if(prime[i]) 
            {
                prime[i]=false;
                for(j=i*i; j<=n; j+=i) 
                {
                    prime[j] = false;
                }
            }
        }
        ll count=0;

        for(i=2; i<=n; i++) {
            if(prime[i]) {
                count++;
            }
        }
        cout<<count<<"\n";

    }
    return 0;
}