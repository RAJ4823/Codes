#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool sortbysec(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return (a.second < b.second);
}

int main()
{
    int t, caseNo = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<pair<ll, ll>> v(n), ans(n);

        for (int i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            v[i] = {x, i};
        }
        sort(v.begin(), v.end());

        int i = 0, j = n - 1;
        pair<ll, ll> temp;
        while (i < n)
        {
            if (i == j)
            {
                j--;
                continue;
            }
            if (v[j].first <= v[i].first * 2)
            {
                ans[i] = {v[j].first, v[i].second};
                temp = ans[i];
                i++;
                j = n - 1;
            }
            else if (j == 1)
            {
                ans[i] = {-1, v[i].second};
                i++;
                j = n - 1;
            }
            else
                j--;
            // if (i != n - 1)
            //     j = n - 1;
        }
        ans[n - 1] = {v[n - 2].first, v[n - 1].second};
        sort(ans.begin(), ans.end(), sortbysec);

        // for (auto &x : ans)
        //     cout << x.first << ' ' << x.second << endl;

        cout << "Case #" << caseNo << ": ";
        for (auto &x : ans)
            cout << x.first << ' ';
        cout << endl;

        caseNo++;
    }
    return 0;
}