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
        string s;
        int n,count1 = 0,count2 = 0;
        cin >> n;
        cin >> s;

        for(int i=0; i<n-1; i++)
        {
            if(s[i] =='0' && s[i+1] == '0')
                count1+=2;
        }
        for(int i=0; i<n-1; i++)
        {
            if(s[i-1] == '0' && s[i] == '1' && s[i+1] == '0')
                count1++;
        }
        cout << count1 << endl;
    } 
    return 0;
}