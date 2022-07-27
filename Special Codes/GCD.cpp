#include <bits/stdc++.h>
#define ll long long
using namespace std;

int gcd(int a,int b)
{
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        int a, b;
        cin >> a >> b;
        cout << gcd(a,b) << endl;
    }
    return 0;
}