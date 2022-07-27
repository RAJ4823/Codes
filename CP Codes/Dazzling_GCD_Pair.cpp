#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll t;
    cin >> t;

    while (t--)
    {
        ll a, b, x, y;
        cin >> a >> b;
        
        if (a % 2 == 0)
        {
            if (b-a <= 1)
                cout << -1 << endl;
            else
                cout << a << " " << a + 2 << endl;
        }
        else
        {
            x = a + 1;
            y = a + 3;
            if (b-x <= 1)
                cout << -1 << endl;
            else
            {
                if (a % 3 == 0)
                    cout << a << " " << a + 3 << endl;
                else
                    cout << x << " " << y << endl;
            }
        }
    }
    return 0;
}