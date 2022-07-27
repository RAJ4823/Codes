#include <bits/stdc++.h>
using namespace std;
vector<int> v[2001];
int maxi = -1;
void dfs(int x, int level)
{
    maxi = max(maxi, level);
    for (int i = 0; i < v[x].size(); i++)
    {
        dfs(v[x][i], level + 1);
    }
}
int main()
{
    int n, i, x;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == -1)
            x++;
        v[x].push_back(i);
    }
    for (i = 0; i < v[0].size(); i++)
    {
        dfs(v[0][i], 1);
    }
    cout << maxi << endl;
    return 0;
}