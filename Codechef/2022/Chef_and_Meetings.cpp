#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define yn(x) (x) ? cout << "YES\n" : cout << "NO\n";
#define ynif(x, y) (x == y) ? cout << "YES\n" : cout << "NO\n";
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " | " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

int minutes(string s1, string s2)
{
    int hour, min;
    hour = (s1[0] - 48) * 10 + (s1[1] - 48);
    min = (s1[3] - 48) * 10 + (s1[4] - 48);
    // cout << hour << " " << min << endl;
    // cout << s1[0] << " " << s1[1] <<  endl;
    if (s2 == "AM")
    {
        if (hour == 12)
            hour = 0;
    }
    else
    {
        hour += 12;
        if (hour == 24)
            hour = 12;
    }
    return (hour * 60 + min);
}
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int time = minutes(s1, s2), q;

        cin >> q;
        while (q--)
        {
            string a1, a2, b1, b2;
            cin >> a1 >> a2;
            cin >> b1 >> b2;

            int time1 = minutes(a1, a2);
            int time2 = minutes(b1, b2);

            if (time1 <= time && time <= time2)
                cout << 1;
            else
                cout << 0;
            // cout << time1 << " " << time2 << endl;
        }
        cout << endl;
    }
    return 0;
}