#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a[4], sum = 0, ans = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        if (sum == 4)
            ans = 2;
        else if (sum == 0)
            ans = 0;
        else
            ans = 1;
        cout << ans << endl;
    }
    return 0;
}