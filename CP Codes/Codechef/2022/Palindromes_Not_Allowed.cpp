#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int t;
    cin>>t;
    int alpha;

    while(t--)
    {
        int n;
        cin >> n;
        for(int i=0; i<n; i++) {
            printf("%c",((i%4)+97));
        }
        cout << endl;
        
    }
    return 0;
}