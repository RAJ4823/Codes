#include <bits/stdc++.h>
#define ll long long
using namespace std;

int check[2500][2500];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    char arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    int a = 0;
    int ans = 0, flag = 1;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (arr[i][j] == '#')
            {
                check[i][j] ++;
                break;
            }
            else
            {
                if (arr[i - 1][j] == '.' && arr[i + 1][j] == '.' && arr[i][j - 1] == '.' && arr[i][j + 1] == '.' && check[i - 1][j] == 0 && check[i + 1][j] == 0 && check[i][j - 1] == 0 && check[i][j + 1] == 0)
                {
                    ans = 1;
                    check[i][j + 1]++;
                    check[i + 1][j]++;
                }
                else
                {
                    ans = 0;
                }
            }
        }
    }

    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<n; j++) {

    //     }
    // }

    if (ans)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
}