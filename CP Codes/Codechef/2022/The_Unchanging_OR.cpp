#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = log2(n)+1;
        cout << (n-ans) << endl;
        
    }
    return 0;
}