#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    if (n == 1 && t == 10)
    {
        cout << "-1\n";
        return 0;
    }
    if (t < 10)
    {
        for (int i = 1; i <= n; i++)
            cout << t;
    }
    else
    {
        cout << 1;
        for (int i = 1; i < n; i++)
            cout << 0;
    }
    cout << endl;
    return 0;
}