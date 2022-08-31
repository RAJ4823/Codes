#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;

    int ans1 = max((a + b) * c, (b + c) * a);
    int ans2 = max((a * b) + c, (b * c) + a);
    int ans3 = max(a * b * c, a + b + c);

    cout << max(ans1, max(ans2, ans3)) << endl;
    return 0;
}