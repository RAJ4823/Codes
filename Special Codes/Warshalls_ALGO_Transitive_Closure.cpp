#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n;
    cout << "ENTER NUMBER OF ELEMENTS : ";
    cin >> n;

    int m[n][n] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            m[i][j] = 0;

        int a, b;
    vector<pair<int, int>> v;
    set<int> s;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        s.insert(a);
        s.insert(b);

        v.push_back({a, b});
        m[a - 1][b - 1] = 1;
    }
    cout << s.size() << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}