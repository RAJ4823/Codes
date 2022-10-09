#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(vector<int> &v, int n, int m)
{
    int ans = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int temp = i + 1;
        for (int j = n - 1; j > i; j--)
        {
            temp += (v[j] / v[i]);
            if (v[j] % v[i] != 0)
                temp++;
            if (temp > m)
            {
                cout << ans << endl;
                return;
            }
        }
        ans = min(v[i], ans);
    }
    cout << ans << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    unordered_map<int, int> mp;
    map<int, int> in;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        mp[v[i]]++;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
        in[v[i]] = i;
    for (auto i : in)
    {
        int j = i.second + 1;
        int temp = j;
        while (j < n)
        {
            int div = (v[j] / v[i.second]);
            if (v[j] % v[i.second] != 0)
                div++;
            temp += mp[i.first] * div;
            j += in[j];
        }
    }
    cout << endl;
    // solve(v, n, m);
    return 0;
}