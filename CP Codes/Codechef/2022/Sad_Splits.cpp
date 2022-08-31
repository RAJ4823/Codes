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

        int first = n % 10;
        int second;
        bool answer = false;

        n /= 10;
        while (n != 0)
        {
            second = n % 10;
            if (first % 2 == second % 2)
            {
                answer = true;
                break;
            }
            n /= 10;
        }

        if (answer) 
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}