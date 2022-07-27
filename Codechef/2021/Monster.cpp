#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e4;

int main()
{
    ll a,b;
    ll c,d;
    cin >> a >> b;
    cin >> c >> d;

    if(b==d)
    {
        cout << b << endl;
    }
    else{
    for(ll i=0; i<1000; ++i)
    {
        for(ll j=0; j<=1000; ++j)
        {
            if(b+i*a==d+j*c)
            {
                cout << (b+i*a) << endl;
                return 0;
            }
        }
    }
    }
    cout << "-1" << endl;

    return 0;
}