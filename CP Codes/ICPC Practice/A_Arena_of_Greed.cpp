#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll find(ll n)
{
    if (n == 1)
        return 1ll;
    if (n <= 4)
        return n - 1;
    if (n % 4 == 0 || n % 2 == 1)
        return (n - find(n - 1));
    return (n - find(n / 2));
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        cout << find(n) << endl;
    }
    return 0;
}