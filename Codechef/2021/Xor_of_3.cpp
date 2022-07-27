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
        int  n, ans=0;
        cin >> n;
        int a[n], test[n];
        
        for(int i=0; i<n; ++i) {
            cin >> a[i];
        }

        if(a[n-1]==1) {
            cout << "NO" <<endl;
        }
        else {
            for(int i=n-1; i>=0; i--) {
                if(a[i]==1){
                    if(a[i-1]==1) {
                        test[ans] = i;
                        ans++;
                        a[i-1] = 0;
                    }
                    else {
                        test[ans] = i+1;
                        ans++;
                        a[i] = 0;
                    }
                }
            }
            cout << "YES\n" << ans << endl;
            for(int i = 0; i < ans; ++i) {
                cout << test[i] << " ";
            }

            if(ans!=0)
            cout << endl;
        }
        

    }
    return 0;
}