#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n], diff[n];
    diff[0] = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i > 0)
        diff[i] = arr[i] - arr[i - 1];
    }

    sort(diff, diff + n);
    int sum = k;

    for (int i = 1; i <= n - k; i++)
    {
        sum += diff[i];
    }

    cout << sum << endl;

    return 0;
}