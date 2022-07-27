#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin >> n;
    int ans = n;
    for(int i=1; i<=n; i++) {
        ans += (n-i)*i;
    }
    cout << ans << endl;
    return 0;
}