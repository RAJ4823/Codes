#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll a1,a2;
        ll b1,b2;
        ll c1,c2;

        cin >> a1 >> a2;
        cin >> b1 >> b2;
        cin >> c1 >> c2;

        cout << max(a1+a2,max(b1+b2,c1+c2));
    }
    return 0;
}