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
        ll N,K;
        cin >> N >>K;

        if(K%2==0) //even
        {
            cout << (2*N - K - 2) << endl;
        }
        else //odd
        {
            cout << (2*N - K - 1) << endl; 
        }

    }
    return 0;
}