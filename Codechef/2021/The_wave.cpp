#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,q, temp =0;
    cin >> n >> q;
    vector<ll> a;

    for(int i=0;i<n; ++i)
    {
        cin>>temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());

    for(int i=0;i<q; ++i)
    {
        ll x = 0;
        cin>> x;
        {
            auto num = lower_bound(a.begin(), a.end(), x); 
            //first element which >= x
            // index = (num - a.begin())
            ll sum = n - (num - a.begin()); 
            //total elements, which are > x
            
            if(x == *num)
                cout<<"0\n";
            else if(sum%2)
                cout<<"NEGATIVE\n";
            else
                cout<<"POSITIVE\n";
        }
    }
    return 0;
}