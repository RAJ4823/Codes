#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Disjoint Set is an another data structure to store the graph components
// It is used to find weather the nodes are in same component or not in constant time
// Actual Time Complexity is O(4 * a) where a is constant and it's value is nearly close to 1.

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    // Will find the ultimate parent of the node
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    // Rank is the level of node
    void unionByRank(int u, int v)
    {
        int root_u = findUPar(u); // Ultimate parent of 'u'
        int root_v = findUPar(v); // Ultimate parent of 'v'

        if (root_u == root_v)
            return;

        // Connect smaller component to bigger component (by rank)
        if (rank[root_u] < rank[root_v])
            parent[root_u] = root_v;
        else if (rank[root_u] > rank[root_v])
            parent[root_v] = root_u;
        else
        {
            // If rank is same then connection order doesnot matter
            parent[root_v] = root_u;
            rank[root_u]++; // Increase the rank of ultimate parent
        }
    }

    // Size is the total number of nodes
    void unionBySize(int u, int v)
    {
        int root_u = findUPar(u); // Ultimate parent of 'u'
        int root_v = findUPar(v); // Ultimate parent of 'v'

        if (root_u == root_v)
            return;

        // Connect smaller component to bigger component (by size)
        // And increase size of bigger component by adding size of smaler component
        if (size[root_u] < size[root_v])
        {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
        }
        else
        {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
        }
    }
};

int main()
{
    // Will create the DisjointSet of total 7 nodes by '1 based indexing'
    DisjointSet ds1(7);
    ds1.unionByRank(1, 2);
    ds1.unionByRank(2, 3);
    ds1.unionByRank(4, 5);
    ds1.unionByRank(6, 7);
    ds1.unionByRank(5, 6);

    // Checking weather are nodes in same component or not
    // ds1.unionByRank(2, 5) ;
    if (ds1.findUPar(3) == ds1.findUPar(7))
        cout << "Same\n";
    else
        cout << "Not Same\n";

    DisjointSet ds2(7);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(2, 3);
    ds2.unionBySize(4, 5);
    ds2.unionBySize(6, 7);
    ds2.unionBySize(5, 6);

    // Checking weather are nodes in same component or not
    ds2.unionBySize(2, 5);
    if (ds2.findUPar(3) == ds2.findUPar(7))
        cout << "Same\n";
    else
        cout << "Not Same\n";
}