#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
       
        ll A = ((2 * b) - c) % a;
        ll B = (a + c) % (2*b);
        ll C = ((2 * b) - a) % c;

        if (A==0 && 2*b>c || B==0 || C==0 && 2*b>a)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}