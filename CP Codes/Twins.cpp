#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int n;
    cin >> n;

    int a[n], sum = 0, tot = 0;
    int ans = n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        tot += a[i];
    }
    sort(a, a + n);
    int sum1 = 0, sum2 = tot;
    for (int i = 0; i < n; i++)
    {
        sum1 += a[i];
        sum2 -= a[i];
        cout << a[i] << " "<< sum1 <<  " " << sum2 << endl;
        if (sum1 < sum2)
        {
            ans--;
        }
    }

    cout <<  ans << endl;
    return 0;
}