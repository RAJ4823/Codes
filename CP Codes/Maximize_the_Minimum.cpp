#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        int a[n];
        // vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            // v.push_back(make_pair(a[i], i));
        }
        sort(a, a+n);
        // sort(v.begin(), v.end());

        if (k + 1 >= n)
        {
            cout << a[n-1] << endl;
        }
        else
        {
            cout << a[k] << endl;
        }
    }
    return 0;
}