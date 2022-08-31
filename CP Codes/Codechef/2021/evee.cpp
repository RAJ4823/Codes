#include <bits/stdc++.h>
#define ll long long
using namespace std;

string s[] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    string str;
    vector<bool> evee(8,true);
    
    cin>>n;
    cin>>str;

    if(n==8)
    {
        cout<<s[0]<<endl;
        return 0;
    }
    else if(n==6)
    {
        cout<<s[3]<<endl;
        return 0;
    }
    for(int i=0;i<n;++i)
    {
        if(str[i]=='.')continue;
        for(int j=0;j<8;++j)
            if(evee[j] && str[i]!=s[j][i])
                evee[j]=false;
    }
    for(int i=1;i<8;++i)if(evee[i])
        cout<<s[i]<<endl;

    return 0;
}