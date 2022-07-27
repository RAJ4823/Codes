#include <bits/stdc++.h>
#define ll long long
#define f(i,a,b) for(i=a;i<b;i++)
#define mod 1000000007

#define mp make_pair
#define uniq(v) (v).erase(unique (all(v)), (v).end())
#define ff first
#define ss second
#define rf(i, a,b) for(int i=a;i>=b;i--)
#define sc(a) scanf("%lld",&a) 
#define pf printf 
#define sz(a) (int)(a.size())
#define psf push_front
#define ppf pop_front
#define ppb pop_back
#define pb push_back
#define pq priority_queue
#define all(s) s.begin(),s.end()
#define sp(a) setprecision(a)
#define rz resize
#define ld long double 
#define inf (11)1e18
#define ub upper_bound
#define lb lower_bound
#define bs binary_search
#define eb emplace_back

const double pi= acos(-1);

ll binpow(ll a , ll b, ll md)
{
    ll res=1;
    while(b!=0)
    {
        if(b&1)
        res*=a,res%=md;a*=a,a%=md;
        b>>=1;
    }return res%=md;
}    

using namespace std;
ll ans;

vector<vector<int>> v;
vector<ll> dp,tot;


void dfs(int cur,int par)
{

    dp[cur]=1,tot[cur]=1;
    ll sum=0, cnt=0;
    int i;

    f(i,0,sz(v[cur]))
    {
        ll node=v[cur][i];

        if(node!=par)
        {
            dfs(node,cur);

            dp[cur]+=((2* dp[node])%mod), dp[cur]%=mod, cnt++,tot[cur]+=tot[node], tot[cur]%=mod, tot[cur] += dp[node], tot[cur] %= mod;
            sum+=dp[node];
        }
    }


    f(i,0,sz(v[cur]))
    {
        int node=v[cur][i];

        if(node!=par)
        {
            tot[cur] += (dp[node]*((sum-dp[node]+mod)%mod))%mod;
            tot[cur] %= mod;
        }
    }

}


int main() 
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);

    int z, i ,j;
    cin>>z;

    while(z--)
    {
        ans=0;
        int n;
        cin>>n;

        v.rz(n+1),dp.rz(n+1),tot.rz(n+1);

        f(i,0,n-1)
        {
            int l,r;
            cin>>l>>r;

            v[l].pb(r),v[r].pb(l);
        }

        dfs(1,1);

        ll ans = tot[1]%mod;    
        cout<<ans<<"\n";

        dp.clear(),v.clear(),tot.clear();
    }
    return 0;
}