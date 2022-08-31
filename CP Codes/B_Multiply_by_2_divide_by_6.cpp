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
        ll n;
        cin >> n;

        ll count = 0;
        while (n != 1)
        {
            if (n % 6)
            {
                while (n % 6 != 0)
                {
                    n *= 2;
                    count++;
                }
            }
            else
            {
                while (n % 6 != 0)
                {
                    n /= 6;
                    count++;
                }
            }
        }

        cout << count << endl;
    }
    return 0;
}