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

void dfs(int i, int j, int oldColor, int newColor, vector<vector<int>> &image)
{
    int n = image.size();    // rows
    int m = image[0].size(); // collumn
    if (i < 0 || j < 0)
        return;
    if (i >= n || j >= m)
        return;
    if (image[i][j] != oldColor)
        return;

    image[i][j] = newColor;

    dfs(i - 1, j, oldColor, newColor, image);
    dfs(i + 1, j, oldColor, newColor, image);
    dfs(i, j - 1, oldColor, newColor, image);
    dfs(i, j + 1, oldColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int oldColor = image[sr][sc];
    if (oldColor == newColor)
        return image;
    dfs(sr, sc, oldColor, newColor, image);
    return image;
}

int main()
{
    int n, m, sr, sc, newColor;
    cin >> n >> m;
    cin >> sr >> sc >> newColor;
    vector<vector<int>> image;

    f(i, n)
    {
        vector<int> temp(m, 0);
        f(j, m)
            cin >>temp[j];
        image.push_back(temp);
    }

    vector<vector<int>> ans;
    ans = floodFill(image, sr, sc, newColor);

    f(i, n)
    {
        f(j, m)
        {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}