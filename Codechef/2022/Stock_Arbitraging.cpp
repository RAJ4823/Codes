#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n, m, r, i;
    cin >> n >> m >> r;
    int mini[n];
    int maxi[m];

    for (i = 0; i < n; i++)
        cin >> mini[i];

    for (i = 0; i < m; i++)
        cin >> maxi[i];

    sort(mini, mini + n);
    sort(maxi, maxi + m);

    int share = 0;
    if (mini[0] < maxi[m - 1])
    {
        int remain = r % mini[0];
        share = (((r - remain) * maxi[m - 1]) / mini[0]) + remain;
    }
    else
    {
        share = r;
    }

    cout << share << endl;

    return 0;
}