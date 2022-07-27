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
        int a,b,c,d,e;
        cin >> a >> b >> c >> d >> e;
        int s1 = a+b;
        int s2 = a+c;
        int s3 = b+c;

        if(s1<=d && c<=e) 
        cout << "YES\n";
        else if(s2<=d && b<=e)
        cout << "YES\n";
        else if(s3<=d && a<=e)
        cout << "YES\n";
        else
        cout << "NO\n";

    }
    return 0;
}