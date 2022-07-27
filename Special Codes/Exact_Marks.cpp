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
        ll n, x;

        cin >> n >> x;
        ll a,b,c;

        if(x%3 == 0) {
            a = x/3;
            b = 0;
            c = n-a;
        }
        else {
            a = (x/3)+1;
            b = a*3 - x;
            c = n - (a+b);
        }

        if(a+b+c == n && a>=0 && b>=0 && c>=0) {
            cout << "YES\n";
            cout << a << ' ' << b << ' ' << c << endl;
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}