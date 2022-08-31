#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    set<pair<int, int>> s;
    int n;
    cin >> n;
    int x, y;

    vector<pair<int, int>> v;
    map<pair<int, int>, int> m;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pair<int, int> p(x, y);

        s.insert(p);
        m[p] = i;
        v.push_back(p);
    }

    pair<int, int> p0;
    pair<int, int> p1;
    pair<int, int> p2;
    pair<int, int> p3;
    pair<int, int> p4;
    pair<int, int> p5;
    pair<int, int> p6;
    int i = 1;

    for (auto &var : s)
    {
        pair<int, int> p0(var.first, var.second);
        int index = m[p0];

        while(true)
        {
            p1 = make_pair(v[index].first - i, v[index].second);
            p2 = make_pair(v[index].first + i, v[index].second);
            p3 = make_pair(v[index].first, v[index].second - i);
            p4 = make_pair(v[index].first, v[index].second + i);
            p5 = make_pair(v[index].first - i, v[index].second - i);
            p6 = make_pair(v[index].first + i, v[index].second + i);


            if (s.find(p1) == s.end())
            {
                v[index].first = v[index].first - i;
                v[index].second = v[index].second;
                break;
            }
             if (s.find(p2) == s.end())
            {
                v[index].first = v[index].first + i;
                v[index].second = v[index].second;
                break;
            }
             if (s.find(p3) == s.end())
            {
                v[index].first = v[index].first;
                v[index].second = v[index].second - i;
                break;
            }
             if (s.find(p4) == s.end())
            {
                v[index].first = v[index].first;
                v[index].second = v[index].second + i;
                break;
            }
             if (s.find(p5) == s.end())
            {
                v[index].first = v[index].first - i;
                v[index].second = v[index].second - i;
                break;
            }
             if (s.find(p6) == s.end())
            {
                v[index].first = v[index].first + i;
                v[index].second = v[index].second + i;
                break;
            }
            i++;
        }
    }
    for (auto &pi : v)
    {
        cout << pi.first << " " << pi.second << endl;
    }

    return 0;
}