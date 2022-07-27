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
        ll n;
        cin >> n;
        ll x = n/5;
        ll y = n - x*5;
        cout << x*4 + y << endl;
    }
    return 0;
}