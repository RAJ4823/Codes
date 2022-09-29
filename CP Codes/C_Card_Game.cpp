#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define fauto(i, a) for (auto &i : a)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 998244353ll

// ll power(ll a, ll b, ll mod){ 
// 	ll x = 1, y = a; 
// 	while (b > 0){ 
// 		if (b%2){ 
// 			x = (x*y)%mod; 
// 		} 
// 		y = (y*y)%mod; 
// 		b /= 2; 
// 	} 
// 	return x%mod; 
// }	 
 
// ll modular_inverse(ll n, ll mod){ 
// 	return power(n, mod-2, mod); 
// } 
 
// ll nCr(ll n, ll k, ll mod){ 
// 	return (factorial[n]*((modular_inverse(factorial[k]*modular_inverse(factorial[n-k]))%mod))%mod; 
// } 

int main()
{
    // Pre computed
    ll calc[30][2] = {{1, 0}, {3, 2}, {12, 7}, {42, 27}, {153, 98}, {560, 363}, {2079, 1352}, {7787, 5082}, {29392, 19227}, {111605, 73150}, {425866, 279565}, {1631643, 1072512}, {6272812, 4127787}, {24186087, 15930512}, {93489272, 61628247}, {362168442, 238911947}, {407470704, 927891162}, {474237047, 614943428}, {319176974, 87534470}, {131938523, 955113935}, {558075845, 644336680}, {544270478, 253841470}, {209493498, 700054910}, {859106804, 457241336}, {921005664, 6522991}, {366933608, 353887625}, {142064435, 432533537}, {741221694, 874398972}, {297907370, 545598131}, {341102826, 248150916}};
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll i = n / 2 - 1;
        cout << calc[i][0] << ' ' << calc[i][1] << ' ' << 1 << endl;
    }
}