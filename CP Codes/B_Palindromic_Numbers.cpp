#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define fauto(i, a) for (auto &i : a)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

string findDiff(string str1, string str2)
{
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
    int carry = 0;
    for (int i = 0; i < n2; i++)
    {
        int sub = ((str1[i] - '0') - (str2[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    for (int i = n2; i < n1; i++)
    {
        int sub = ((str1[i] - '0') - carry);
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;
        str.push_back(sub + '0');
    }
    reverse(str.begin(), str.end());
    return str;
}

void remove_zero(string str)
{
    const regex pattern("^0+(?!$)");
    str = regex_replace(str, pattern, "");
    cout << str << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        int dig = (s[0] - 48);
        if (dig >= 8)
        {
            string s2(n + 1, '1');
            string ans = findDiff(s2, s);
            remove_zero(ans);
        }
        else
        {
            string s2(n, dig + 50);
            string ans = findDiff(s2, s);
            cout << ans << endl;
        }
    }
    return 0;
}