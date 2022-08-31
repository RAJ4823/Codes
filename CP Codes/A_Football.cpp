#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string s;
    cin >> s;
    bool ans = false;
    int count1= 0, count0 = 0;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]-48)
        {
            count1++;
            count0 = 0;
        }
        else
        {
            count0++;
            count1 = 0;
        }
        if(count1 == 7 || count0 == 7)
        {
            ans = true;
            break;
        }

    }
    if(ans)
        cout << "YES\n";
    else
        cout <<"NO\n";
    return 0;
}