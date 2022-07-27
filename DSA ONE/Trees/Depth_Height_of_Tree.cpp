#include <bits/stdc++.h>
using namespace std;
#define ll long long
// Implementing tree as a graph
// Using dfs to traverse and calculate height , depth of tree
vector<int> height(100, 0);
vector<int> depth(100, 0);
void dfs(vector<int> tree[], int root, int parent)
{
    for (auto child : tree[root])
    {
        if (child == parent)
            continue;
        depth[child] = depth[root] + 1;
        dfs(tree, child, root);
        height[root] = max(height[root], height[child] + 1);
    }
}

void display(int n)
{
    cout << "\nNodes  :";
    for (int i = 1; i <= n; i++)
        cout << i << ' ';
    cout << "\nHeight :";
    for (int i = 1; i <= n; i++)
        cout << height[i] << ' ';
    cout << "\nDepth  :";
    for (int i = 1; i <= n; i++)
        cout << depth[i] << ' ';
}

int main()
{
    int n, root;
    cout << "Enter number of nodes : ";
    cin >> n;
    cout << "Enter edges : ";

    vector<int> tree[n + 1];

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    cout << "Enter root node : ";
    cin >> root;
    dfs(tree, root, 0);
    display(n);

    return 0;
}