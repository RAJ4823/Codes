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

        if(log2(n) == (int)log2(n))
            cout << "NO\n";
        else
            cout << "YES\n";
        
    }
    return 0;
}