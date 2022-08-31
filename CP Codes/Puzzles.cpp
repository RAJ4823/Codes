#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[m], ans = INT_MAX;
    int A, B;

    for (int i = 0; i < m; i++)
        cin >> a[i];
    sort(a, a + m);
    
    for (int i = 0; n+i <= m; i++)
    {
        A = a[i];
        B = a[n+i-1];
        ans = min(ans, (B-A));
        // cout << "A - " << A << " B - " << B << " ANS - " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}