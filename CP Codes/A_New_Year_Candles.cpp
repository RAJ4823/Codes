#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = a, rem = 0;
    while (a >= b)
    {
        ans += a / b;
        a = (a / b) + (a % b);
    }
    cout << ans << endl;
    return 0;
}