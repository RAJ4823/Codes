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

        ll s = 1;
        for (ll i = 1; i <= n; i++)
        {
            if (i % 2)
                s = i;
            else
                s = s*2;
            
            cout << s << " ";
        }
    
        cout << "\n";
    }
    return 0;
}