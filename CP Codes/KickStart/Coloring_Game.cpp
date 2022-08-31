#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t, caseNo = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = (n+3)/4;
        cout << "Case #" << caseNo << ": "<< ans << endl;
        caseNo++;
    }
}