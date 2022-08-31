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
        int n,p,k;
        int cnt = 0;
        cin >> n >> p >> k;
        int ck = p%k;

        for(int i=0; i<n; i++){

            if(i<=p && i%k == ck){
                cnt ++;
                cout << i << " mod " << k << " = " << i%k << endl;
            }
            if(i%k < ck){
                cnt ++;
                cout << i << " mod " << k << " = " << i%k << endl;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}