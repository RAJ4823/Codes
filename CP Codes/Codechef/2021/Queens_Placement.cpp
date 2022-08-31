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
        int k=n-3;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(i==j){
                    if(i==(n-3) || i==(n-1)){
                        cout << '.';
                    }
                    else
                    cout << 'Q';
                }
                else{
                    cout << '.';
                }
            }
            cout << endl;
            k--;
        }
        
    }
    return 0;
}