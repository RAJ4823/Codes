#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    double x, y, a, b, c, d;
    cin >> x >> y >> a >> b >> c >> d;

    double ans = INT_MAX * 1.0;
    // mindist from corners
    ans = min(ans, sqrt(pow((x - a), 2) + pow((y - b), 2)));
    ans = min(ans, sqrt(pow((x - a), 2) + pow((y - d), 2)));
    ans = min(ans, sqrt(pow((x - c), 2) + pow((y - b), 2)));
    ans = min(ans, sqrt(pow((x - c), 2) + pow((y - d), 2)));
    // mindist from y-line
    if (x >= min(a, c) && x <= max(a, c))
        ans = min(ans, min(abs(y - b), abs(y - d)));
    // mindist from x-line
    if (y >= min(b, d) && y <= max(b, d))
        ans = min(ans, min(abs(x - a), abs(x - c)));

    // cout << ans << endl;
    printf("%.3lf\n", ans);

    return 0;
}