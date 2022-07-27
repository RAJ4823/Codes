#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--)
    {
        int n, ans = 0;
        cin >> n;
        int a[n], b[n];

        for(int i=0; i<n; ++i) 
        cin >> a[i];
        for(int i=0; i<n; ++i) 
        cin >> b[i];

        for(int i=0; i<n; ++i) {
            if(a[0] < b[i]) {
                cout << i << endl;
                break;
            }

            if(b[0] > a[i]) {
                cout << i << endl;
                break;
            }
        }
        
    }
    return 0;
}