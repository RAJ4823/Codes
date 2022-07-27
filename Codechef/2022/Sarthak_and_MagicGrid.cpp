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
        ll n,i,j;
        ll row =1, clm=1, dig=1;
        cin >> n;
        for(i=0; i<n; i++) {
            for(j = 0; j<n; j++) {
                row ^= 1;
            }
            cout << row << endl;
        }
    }
    return 0;
}