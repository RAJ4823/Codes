// ⭐ the_247 | Raj Patel ⭐
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define pqll priority_queue<ll>
#define umll unordered_map<ll, ll>
#define usll unordered_set<ll>
#define mll map<ll, ll>
#define sll set<ll>

#define fauto(i, a) for (auto &i : a)
#define f(i, s, e) for (int i = s; i < e; i++)
#define fr(i, s, e) for (int i = s; i >= e; i--)

#define all(x) (x).begin(), (x).end()
#define sortv(v) sort(all(v))
#define sortvd(v) sort(all(v), greater<>());
#define sortstr(str) sort(all(str))
#define sortstrd(str) sort(all(str), greater<char>())
#define tolowerstr(str) transform(all(str), str.begin(), ::tolower)
#define toupperstr(str) transform(all(str), str.begin(), ::toupper)
#define print_condition(x, s1, s2) cout << ((x) ? s1 : s2) << endl;
#define print_vector(v) fauto(x, v) cout << (x) << ' ';

#define db(x) cout << (#x) << " = " << x << "\n";
#define dbb(x, y) cout << (#x) << " = " << x << " , " << (#y) << " = " << y << "\n"

#define PI 3.1415926535897932384626433832795
#define MOD 1000000007LL
#define MODD 998244353

bool find()
{
    ll n, m, k;
    cin >> n;
    sll st;
    vll arr(n - 1);
    st.insert(n);

    f(i, 0, n - 1)
    {
        cin >> arr[i];
        st.insert(i + 1);
    }

    int value = -1;
    if (st.count(arr[0]))
        st.erase(arr[0]);
    else
        value = arr[0];

    f(i, 1, n - 1)
    {
        ll diff = arr[i] - arr[i - 1];
        if (st.count(diff))
            st.erase(diff);
        else if (value == -1)
            value = diff;
        else
            return false;
    }

    ll remSum = 0;
    fauto(x, st) remSum += x;

    if (value >= 0)
        return (remSum == value);

    ll total = n * (n + 1) / 2;
    return (total - arr[n - 2] == remSum);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        print_condition(find(), "YES", "NO");
    }
}