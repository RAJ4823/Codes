#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mode = 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--)
    {
        ll L, R;
        cin >> L >> R;

        L = L + ((L+3)%3)%mode;
        R = R - ((R-3)%3)%mode;

        ll ans = ((R- L + 3)/3)%mode;

        cout << ans << endl;      
    }
    return 0;
}