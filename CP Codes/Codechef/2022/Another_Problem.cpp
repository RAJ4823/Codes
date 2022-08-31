#include <bits/stdc++.h>
#define ll long long
#define vi vector<ll>
#define mi map<ll, ll>
#define pb push_back
#define mp make_pair
const ll int MX = 1e9 + 7;
#define MOD 10000007
using namespace std;

ll int arr2[MOD] = {0};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll int x = arr2[t];
        cin >> x;
        ll int num = x;
        ll int arr[32];
        ll int i = 0;
        if (x == 1)
        {
            cout << 1 << " " << 3 << " " << 5 << "\n";
            continue;
        }
        if (x == 2)
        {
            cout << 2 << " " << 3 << " " << 4 << "\n";
            continue;
        }
        while (x > 0)
        {
            arr[i] = x % 2;
            x = x / 2;
            i++;
        }
        ll n = i, num1 = 0, sum1, num2 = 0, ind, sum2, count = 0;
        for (int i = 0; i < n; i++)
        {
            // cout<<arr[i]<<" ";
            if (arr[i] == 1)
            {
                count++;
            }
        }
        // cout<<count;
        if (count == 1)
        {
            // cout <<"TEST : "<< endl;
            // cout << num1 << " | " << num2 << " = " << (num1 | num2) << endl;
            // cout << num2 << " | " << num << " = " << (num2 | num) << endl;
            // cout << num << " | " << num1 << " = " << (num | num1) << endl;
            // cout << "ANS : ";
            cout << num + (num / 2) << " " << num << " " << num + (num * 2) << "\n";
        }
        else
        {
            ll int a[n + 1], b[n + 1], num1 = 0, num2 = 0, count2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 1)
                {
                    count2++;
                }
                a[i] = arr[i];
                if (count2 == 1)
                {
                    a[i] = 0;
                }
            }
            count2 = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 1)
                {
                    count2++;
                }
                b[i] = arr[i];
                if (count2 == count)
                {
                    b[i] = 0;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 1)
                {
                    num1 += pow(2, i);
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (b[i] == 1)
                {
                    num2 += pow(2, i);
                }
            }
            cout << num1 << " " << num2 << " " << num << "\n";
        }
    }
    return 0;
}

// #include <bits/stdc++.h>
// #define ll long long
// using namespace std;

// int main()
// {
//     // ios_base::sync_with_stdio(false);
//     // cin.tie(NULL);
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         ll n;
//         cin >> n;
//         if (even)
//         {
//             cout << n << " " << n + 1 << " " << n + 2 << endl;
//         }
//         if (prime)
//         {
//             int a = n / 2;
//             int b = n / 2;
//             if (b % 2 == 0)
//                 b += b / 2;
//             else
//                 b += (b + 1) / 2;
//             int c = n;
//         }

//         int a = n / 2;
//         int b = n / 2;
//         if (b % 2 == 0)
//             b += b / 2;
//         else
//             b += (b + 1) / 2;
//         int c = n;
// cout << a << " | " << b << " = " << (a | b) << endl;
// cout << b << " | " << c << " = " << (b | c) << endl;
// cout << c << " | " << a << " = " << (c | a) << endl;
// cout << (((a | b) & (b | c)) & (c | a)) << endl;

//     }
//     return 0;
// }
