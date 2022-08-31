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
        int N = pow(2,n);
        ll arr[N];

        for(int i=0; i< N; ++i) {
            cin >> arr[i];       
        } 
        sort(arr, arr+N);
    
        if(arr[N-1] - arr[0] > 1){
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
        
    }
    return 0;
}