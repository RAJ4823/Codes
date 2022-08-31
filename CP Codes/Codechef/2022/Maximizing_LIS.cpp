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
        ll n;
        cin >> n;
        ll a[n];
        ll in = 1;
        vector<int> sum;

        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (ll i = 1; i < n; i++)
        {
            if (a[i] > a[i - 1])
            {
                in++;
            }
            else
            {
                sum.push_back(in);
                in = 1;
            }
        }
        sort(sum.begin(), sum.end());
        ll z = sum.size();
        if(z > 1)
        cout << sum[z-1] + sum[z-2] << endl;
        else
        cout << sum[0] << endl;
    }
    return 0;
}