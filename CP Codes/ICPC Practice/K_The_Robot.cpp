// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define vpll vector<pair<ll, ll>>
// #define vvll vector<vector<ll>>
// #define vll vector<ll>
// #define pll pair<ll, ll>
// #define mll map<ll, ll>
// #define fauto(i, a) for (auto &i : a)
// #define f(i, n) for (int i = 0; i < (n); i++)
// #define ff(i, a, b) for (int i = (a); i < (b); i++)
// #define fr(i, n) for (int i = (n); i >= 0; i--)
// #define ffr(i, a, b) for (int i = (a); i >= (b); i--)
// #define db1(x) cout << #x << " = " << (x) << "\n";
// #define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
// #define SIZE 1000001
// #define MOD 1000000007LL

// int valx(char dir)
// {
//     if (dir == 'R')
//         return 1;
//     if (dir == 'L')
//         return -1;
//     return 0;
// }
// int valy(char dir)
// {
//     if (dir == 'U')
//         return 1;
//     if (dir == 'D')
//         return -1;
//     return 0;
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         string s;
//         cin >> s;
//         int x = 0, y = 0;
//         int ans_x = 0, ans_y = 0;
//         f(i, s.size())
//         {
//             x += valx(s[i]);
//             y += valy(s[i]);
//             if (!x && !y)
//                 continue;

//             int nx = 0, ny = 0;
//             f(j, s.size())
//             {
//                 if (nx + valx(s[j]) != x || ny + valy(s[j]) != y)
//                 {
//                     nx += valx(s[j]);
//                     ny += valy(s[j]);
//                 }
//             }

//             if (!nx && !ny)
//             {
//                 ans_x = x;
//                 ans_y = y;
//                 break;
//             }
//         }
//         cout << ans_x << ' ' << ans_y << endl;
//     }
//     return 0;
// }

// ~Anant83
#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define ll long long
#define ld long double
#define mod 1000000007
#define pi 3.141592653589793238
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll,ll>
#define sz(x) ((int)(x).size())
#define vpi vector<pair<int,int>>
#define all(x) x.begin(),x.end()
#define allg(x) x.begin(),x.end(),greater<int>()
#define speed_up ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ull unsigned long long                   
//typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// pbds ps    |||find_by_order, order_of_key
                         
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << "-> ";_print(x);cerr << endl;
#define debug2(x,y) cerr<<#x<<"   ";_print(x);cerr<<"   "<<#y<<"  ";_print(y);cerr<<endl;
#define debug3(x,y,z) cerr<<#x<<"  ";_print(x);cerr<<"  "<<#y<<"  ";_print(y);cerr<<"  "<<#z<<"  ";_print(z);cerr<<endl;
#else
#define debug(x)
#define debug2(x,y)
#define debug3(x,y,z)
#endif
 
template <class T> void _print(T a){cerr << a;}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool isPrime(int n){if(n == 1){return false;}for(int i=2;i*i<=n;i++){if(n%i == 0){return false;}}return true;}
  
    class comp {
     public:
    bool operator()(pair<int,int>&a, pair<int,int>&b)
    {
        if(a.F > b.F)
        return true;

        if(a.F == b.F && a.S < b.S)
        return true;

        return false;
    }
   };
    void solve()
    {
      string s;
      cin>>s;
      int n = sz(s);
      int ansx = 0, ansy = 0;
      for(int i=0; i<n; i++)
      {
        int x = 0,y = 0;
        int tx = 0, ty = 0;
        string s1;
        int start = n;
        for(int j=i+1; j<n; j++)
        {
          if(s[j] != s[i])
          {
            start = j;
            break;
          }
        }
        
        for(int j=0; j<i; j++) {
            if(s1[j] == 'D')
            ty--;
            else if(s1[j] == 'U')
            ty++;
            else if(s1[j] == 'R')
            tx++;
            else
            tx--;
            s1 += s[j];
        }
        for(int j=start; j<n; j++)
        s1 += s[j];
        for(int j=0; j<sz(s1); j++)
        {
          if(s1[j] == 'D')
          y--;
          else if(s1[j] == 'U')
          y++;
          else if(s1[j] == 'R')
          x++;
          else
          x--;
        }
        if(x == 0 && y == 0)
        {
          ansx = tx;
          ansy = ty;
          break;
        }
      }
      cout<< ansx << ' ' << ansy << "\n";
    }
int main(){    
    ll t = 1;
    cin>>t;
    while(t--)
    {
      solve();
    }
return 0;
}