#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

int dfs(int i, int j, int prev, vector<vector<int>> &matrix)
{
    int ans = 0;
    for(auto cur: matrix[prev])
    {
        
    }

  
}
int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int ans = 0;
    f(i, matrix.size())
    {
        f(j, matrix[0].size())
        {
            ans = max(dfs(i, j, 0, matrix), ans);
        }
    }
    return ans;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix;
    f(i, n)
    {
        vector<int> temp(m, 0);
        f(j, m)
        {
            cin >> temp[j];
        }
        matrix.push_back(temp);
    }
    cout << longestIncreasingPath(matrix) << endl;
    return 0;
}