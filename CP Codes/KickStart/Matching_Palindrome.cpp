#include <bits/stdc++.h>
using namespace std;
#define ll long long

string getString(string str, int n)
{
    vector<int> arr(n, 0);
    int i = 1;
    int j = 0;

    while (i < str.length())
    {
        if (str[i] == str[j])
        {
            j++;
            arr[i] = j;
            i++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = arr[j - 1];
        }
    }
    int x = arr[n - 1];
    if (n % (n - x) == 0)
        return str.substr(0, n - x);
    return str;
}

int main()
{
    int t, caseNo = 1;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        string ans = getString(s, n);
        cout << "Case #" << caseNo << ": " << ans << endl;
        caseNo++;
    }
}