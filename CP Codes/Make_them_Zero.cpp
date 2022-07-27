#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define yn(x) (x) ? cout << "YES\n" : cout << "NO\n";
#define ynif(x, y) (x == y) ? cout << "YES\n" : cout << "NO\n";
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " | " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

ll count(ll a, map<ll, ll> &m)
{
    if (a == 0)
        return 0;
    ll p = log2(a);
    ll b = pow(2, p);
    m[b] = 1;
    return count(a - b, m);
}

int main()
{
    // your code goes here
    int t;
    cin >> t;

    while (t--)
    {
        ll n, ans = 0;
        cin >> n;
        bool flag = false;
        map<ll, ll> m;

        ll a[n];
        f(i, n)
        {
            cin >> a[i];
            if (a[i] % 2)
            {
                ans = 1;
                a[i]--;
            }
        }
        sort(a, a + n);
        f(i, n)
        {
            if(log2(a[i]) == (int)(log2(a[i])))
                m[a[i]] = 1;
            else
                count(a[i], m);
        }
        ans += m.size();

        cout << ans << endl;
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// int db(long long int x)
// {
//     int binary = 0, remainder, product = 1;
//     while (x != 0)
//     {
//         remainder = x % 2;
//         binary = binary + (remainder * product);
//         x = x / 2;
//         product *= 10;
//     }
//     string s = to_string(binary);
//     return s.length();
// }
// int main()
// {
//     // your code goes here
//     long long int t;
//     cin >> t;
//     while (t--)
//     {
//         long long int n, ans = 0, flag = 0;
//         cin >> n;
//         long long int arr[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//             if (arr[i] % 2 != 0)
//             {
//                 flag = 1;
//             }
//         }
//         sort(arr, arr + n);
//         ans = db(arr[n - 1]);
//         if (!flag)
//         {
//             cout << ans - 1 << "\n";
//         }
//         else
//         {
//             cout << ans << "\n";
//         }
//     }
//     return 0;
// }