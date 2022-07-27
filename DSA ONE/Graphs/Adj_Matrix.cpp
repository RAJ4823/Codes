#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int v, e;
    cout << "Enter number of vertices : ";
    cin >> v;
    cout << "Enter number of edges : ";
    cin >> e;

    int m[v + 1][v + 1];
    cout << "Enter vertices which are connected\n";

    for (int i = 0; i < e; i++)
    {
        int src, dst;
        cin >> src >> dst;
        m[src][dst] = 1;
        m[dst][src] = 1;
    }

    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            if (m[i][j] == 1)
                cout << 1 << ' ';
            else
                cout << 0 << ' ';
        }
        cout << endl;
    }
    return 0;
}