#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
        }
        int x = a[0]%2, y = a[1]%2;
        bool ans = true;

        for(int i=0; i<n; i++)
        {
            if(x != a[i]%2 && i%2 == 0)
            {
                ans = false;
                break;
            }
            if(y != a[i]%2 && i%2 == 1)
            {
                ans = false;
                break;
            }
        }
        if(ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}