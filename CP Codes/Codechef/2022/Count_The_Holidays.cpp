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
        int n, count = 8;
        cin >> n;
        int a[n];

        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        for(int i=0; i<n; i++) {
            if(a[i]%7 == 0 || (a[i]+1)%7 == 0) {
               continue;
            }
            else {
                count++;
            }
        }

        cout << count << endl;
        
    }
    return 0;
}