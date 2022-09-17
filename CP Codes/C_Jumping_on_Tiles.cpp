//! NOT COMPLETED :(

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define fauto(i, a) for (auto &i : a)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

int getIndex(vpll &vp, int key)
{
    f(i, vp.size()) if (vp[i].second == key) return i;
    return 0;
}

bool fun(const pll &a, const pll &b)
{
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        vpll vp(n);
        mll count;
        vll path, temp;

        f(i, n)
        {
            int num = (int)(s[i] - 96);
            vp[i] = {num, i};
            count[num]++;
        }
        auto f = vp[0], l = vp[n - 1];
        sort(vp.begin(), vp.end());

        int start = getIndex(vp, 0);
        int end = getIndex(vp, n - 1);

        // DEBUG
        // fauto(x, vp)
        // {
        //     cout << x.first << '-' << x.second + 1 << ' ';
        // }
        // cout << endl;

        int i = min(start, end);
        int j = max(start, end);

        f(k, n)
        {
            if (k < i)
            {
                if (vp[k].first == vp[i].first)
                    temp.push_back(vp[k].second + 1);
            }
            else if (k <= j)
                path.push_back(vp[k].second + 1);
            else
            {
                if (vp[k].first == vp[j].first)
                    temp.push_back(vp[k].second + 1);
            }
        }

        if (start > end)
            reverse(path.begin(), path.end());

        int diff = abs(vp[start].first - vp[end].first);
        cout << diff << ' ' << path.size() + temp.size() << endl;
        fauto(step, path)
        {
            if (step == n - 1 && start < end)
            {
                fauto(t, temp)
                {
                    cout << t << ' ';
                }
            }
            cout << step << ' ';
            if (step == 1 && start > end)
            {
                fauto(t, temp)
                {
                    cout << t << ' ';
                }
            }
        }

        cout << endl;
    }
    return 0;
}
