#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;

        ll bits = pow(10, (int)log10(n));
        ll d = n - bits;
        // cout << bits << endl;
        cout << d << endl;
    }
    return 0;
}