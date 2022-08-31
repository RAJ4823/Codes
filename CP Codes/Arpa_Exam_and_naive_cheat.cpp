#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, ans;
    cin >> n;
    switch (n % 4)
    {
    case 0:
        ans = 6;
        break;
    case 1:
        ans = 8;
        break;
    case 2:
        ans = 4;
        break;
    case 3:
        ans = 2;
        break;
    }
    if (n)
        cout << ans << endl;
    else
        cout << "1\n";
    return 0;
}