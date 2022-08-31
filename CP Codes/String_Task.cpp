#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string s;
    cin >> s;
    string ans;

    int j = 0;

    transform(s.begin(), s.end(), s.begin(), ::tolower);
    // cout << s;

    for(int i=0; i<s.length(); i++) {
        if(s[i] == 'a' || s[i] == 'e' ||s[i] == 'i' ||s[i] == 'o' ||s[i] == 'u' || s[i] == 'y'){
            continue;
        } else {
            ans.insert(j++, string(1, '.') );
            ans.insert(j++, string(1, s[i]) );
        } 
    }
    cout << ans << endl;
    return 0;
}