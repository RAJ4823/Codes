#include <bits/stdc++.h>
#define ll long long
using namespace std;

//DEBUG OP

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll num;
        cin >> num;
        ll x;

        switch (num % 4)
        {
        case 0:
            x = (num + 3);
            break;
        case 1:
            x = num;
            break;
        default:
            x = 3;
            break;
        }
        cout << x << endl;
    }
    return 0;
}