#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t;
    cin >> t;

    while (t--)
    {
        int n, count = 1;
        cin >> n;
        int arr[n][n];

        if(n == 2)
        {
            cout << "-1\n";
            continue;
        }

        for (int a = 0; a < n; a++)
        {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i + a == j)
                        arr[i][j] = count++;

            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (i == j + a && a > 0)
                        arr[i][j] = count++;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << arr[i][j] << ' ';
            cout << "\n";
        }
    }
    return 0;
}