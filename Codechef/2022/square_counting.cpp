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
        ll s;
        cin >> n >> s;
        ll count = 0;

        count = s/(n*n);
        cout << count << endl;
        
    }
    return 0;
}