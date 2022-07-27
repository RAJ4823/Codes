#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, sum = 0, a;
        cin >> n >> k;
        string str;
        cin >> str;
        int arr[k];
        for (int i = 0; i < n - 1; i++)
        {
            if (str[i] == str[i + 1])
            {
                sum += 2;
            }
            else
            {
                sum += 1;
            }
        }
        for (int i = 0; i < k; i++)
        {
            cin >> a;
            arr[i] = a - 1;
        }
        for (int i = 0; i < k; i++)
        {
            if (str[arr[i]] == '0')
            {
                str[arr[i]] = '1';
            }
            else
            {
                str[arr[i]] = '0';
            }
            
            if (arr[i] != n - 1 && arr[i] != 0)
            {
                if ((str[arr[i]] == str[arr[i] - 1]) && (str[arr[i]] == str[arr[i] + 1]))
                {
                    sum = sum + 2;
                }
                if ((str[arr[i]] != str[arr[i] - 1]) && (str[arr[i]] != str[arr[i] + 1]))
                {
                    sum = sum - 2;
                }
            }
            if (arr[i] == n - 1)
            {
                if (str[arr[i]] == str[arr[i] - 1])
                {
                    sum = sum + 1;
                }
                else if (str[arr[i]] != str[arr[i] - 1])
                {
                    sum = sum - 1;
                }
            }
            if (arr[i] == 0)
            {
                if (str[arr[i]] == str[arr[i] + 1])
                {
                    sum = sum + 1;
                }
                else if (str[arr[i]] != str[arr[i] + 1])
                {
                    sum = sum - 1;
                }
            }
            
            cout << sum << endl;
        }
    }
    return 0;
}