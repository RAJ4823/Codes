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
        ll a, b;
        cin >> a >> b;

        if (a == 0)
            cout << 1 << endl;
        else
            cout << a + (2 * b) + 1 << endl;
    }
    return 0;
}