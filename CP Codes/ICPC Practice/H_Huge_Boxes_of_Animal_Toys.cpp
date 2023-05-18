#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (b == 0 && c == 0)
        {
            if (a % 2 == 0)
                cout << "Tidak Tidak Tidak Ya\n";
            else
                cout << "Ya Tidak Tidak Tidak\n";
        }
        else if (a == 0 && d == 0)
        {
            if (b % 2 == 0)
                cout << "Tidak Tidak Ya Tidak\n";
            else
                cout << "Tidak Ya Tidak Tidak\n";
        }
        else if ((a + b) % 2 == 0)
            cout << "Tidak Tidak Ya Ya\n";
        else
            cout << "Ya Ya Tidak Tidak\n";
    }
    return 0;
}