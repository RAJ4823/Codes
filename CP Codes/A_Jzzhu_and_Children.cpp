#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    deque<pair<int, int>> v;
    int ans = 0, x, y;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        v.push_back(make_pair(x, i + 1));
    }
    while (!v.empty())
    {
        x = v.front().first;
        y = v.front().second;
        if (x > m)
            v.push_back(make_pair(x - m, y));
        v.pop_front();
        ans = y;
    }
    cout << ans << endl;
    return 0;
}