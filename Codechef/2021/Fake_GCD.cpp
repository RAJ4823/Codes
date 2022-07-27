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
        int n;
        cin >> n;

        for(int i=0; i<n; ++i) {
            if(n%2==0) {
                if(i%2==0){
                    cout << (n-i-1) << " ";
                }
                else {
                    cout << (n-i+1) << " ";
                }
            }
            else {
                cout << (n-i) << " ";
            }
        }
        cout << endl;
        
    }
    return 0;
}