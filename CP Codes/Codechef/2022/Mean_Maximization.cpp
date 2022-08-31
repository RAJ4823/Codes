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
        ll int n;
        cin >> n;
        ll int arr[n], a = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
      
        for (int i = 0; i < n-1; i++)
        {
            a += arr[i];
        }
    
        double ans1 = a / (double)(n-1);
        double ans3 = ans1 + arr[n-1];
        std::cout << std::fixed;
        std::cout << std::setprecision(10);
        std::cout << ans3<<"\n";
    }
    return 0;
}