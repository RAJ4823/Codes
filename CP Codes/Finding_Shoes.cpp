#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        int n,m;

        cin >> n >> m;
        int ans;

        if(n > m) {
            ans = (n-m)*2 + m;
        } else {
            ans = n;
        }
        cout << ans << endl;
    }
    return 0;
}