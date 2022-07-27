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
        int n,x;
        int sum = 0, temp;
        cin >> n >> x;
        for(int i=0; i<n-1; i++)
        {
            cin >> temp;
            sum += temp;
        }
        int y = (n*x) - sum;
        if(y < 0)
            cout << 0 << endl;
        else    
            cout << y << endl;

    }
    return 0;
}