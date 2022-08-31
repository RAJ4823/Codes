#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll int n, ans = 0;
    cin >> n;
    char arr[n][n];
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '.' && j<n-1 && i<n-1 && j>0 && i>0)
            {
                if (arr[i - 1][j] == '.' && arr[i][j - 1] == '.' && arr[i][j + 1] == '.' && arr[i + 1][j] == '.')
                {
                    arr[i][j] = '#';
                    arr[i - 1][j] = '#';
                    arr[i][j - 1] = '#';
                    arr[i][j + 1] = '#';
                    arr[i + 1][j] = '#';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == '.')
            {
                ans = 1;
                break;
            }
        }
        if (ans)
        {
            break;
        }
    }
    if (ans)
    {
        cout << "NO\n";
    }
    else if (!ans)
    {
        cout << "YES\n";
    }
    return 0;
}