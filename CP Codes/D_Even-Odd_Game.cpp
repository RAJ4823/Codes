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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vll odd, even;
        f(i, n)
        {
            ll x;
            cin >> x;
            if (x % 2)
                odd.push_back(x);
            else
                even.push_back(x);
        }
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        int i = odd.size() - 1, j = even.size() - 1;
        bool play = true;
        ll alice = 0, bob = 0;

        while (i >= 0 && j >= 0)
        {
            if (play)
            {
                if (odd[i] >= even[j])
                    i--;
                else
                    alice += even[j--];
            }
            else
            {
                if (even[j] >= odd[i])
                    j--;
                else
                    bob += odd[i--];
            }
            play = !play;
        }

        while (i >= 0)
        {
            if (!play)
                bob += odd[i];
            play = !play;
            i--;
        }
        while (j >= 0)
        {
            if (play)
                alice += even[j];
            play = !play;
            j--;
        }

        if (bob == alice)
            cout << "Tie\n";
        else if (bob > alice)
            cout << "Bob\n";
        else
            cout << "Alice\n";
    }
    return 0;
}