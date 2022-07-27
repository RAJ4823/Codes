/*
    Made By : Raj Patel
    Date : 14/6/2021
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vec vector<ll>
#define vvec vector<vec>
#define pll pair<ll, ll>
#define ump  unordered_map<pll, ll, hash_pair>

struct hash_pair 
{
    template <class T1, class T2>

    size_t operator()(const pair<T1, T2>& p) const
    {
        auto H1 = hash<T1>{}(p.first);
        auto H2 = hash<T2>{}(p.second);
        return H1 ^ H2;
    }
};

void first(ll nod, ll par, vvec&G, vec &S, vec &P, vec &C, vec &L, ll curl)
{
    C[nod] = 1; 
    P[nod] = par;
    L[nod] = curl;

    for(auto cnod: G[nod])
    {
        if(cnod != par)
        {
            first(cnod, nod, G, S, P, C, L, curl+1);
            C[nod] += C[cnod];
            S[nod] += S[cnod] + C[cnod];
        }
    }
}

void second(ll nod, ll par, vvec&G, vec &T, vec &S, vec &C, ump & ctDP, ump & Cdp, ll n)
{
    T[nod] = T[par] + n - 2*C[nod];
    for(auto cnod: G[nod])
        if(cnod != par)
        {
            second(cnod, nod, G, T, S, C, ctDP, Cdp, n);

            Cdp[make_pair(nod,cnod)] = C[cnod];
            ctDP[make_pair(nod, cnod)] = S[cnod];
            ctDP[make_pair(cnod, nod)] = T[nod] - S[cnod] - C[cnod];
        }
    Cdp[make_pair(nod, par)] = n - C[nod];
}

void UP(ll& u, ll dist, vvec & RDP)
{
    for(ll i=20; i>=0; i--)
        if((1<<i) <= dist)
        {
            dist -= (1<<i);
            u = RDP[u][i];
        }
}

ll LCA(ll a, ll b, vvec &RDP, vec & L)
{
    ll u = a, v = b;

    if(L[u] > L[v]) UP(u, L[u]-L[v], RDP);
    if(L[u] < L[v]) UP(v, L[v]-L[u], RDP);

    if (u==v) 
    return u;

    for(int i=19; i>=0; i--)
        if(RDP[u][i] != 0 && RDP[u][i] != RDP[v][i])
        u = RDP[u][i], v = RDP[v][i];
    u = RDP[u][0];
    return u;
}

void MidProps(ll &a, ll &b, vvec& RDP, vec &L, vec & v)
{
    ll lca = LCA(a, b, RDP, L);
    ll dist = abs(L[lca] - L[a]) + abs(L[lca] - L[b]);
    ll mva = (dist-1)/2, mvb;
    ll m1 = a, m2;
    UP(m1, mva, RDP);

    mvb = dist - 1 - mva; m2 = b;
    if(m1 != lca) m2 = RDP[m1][0];
    else{
        UP(m2, mvb, RDP);
    }
    v[0] = m1; v[1] = m2;  v[2] = mva; v[3] = mvb;
}

void showRoute(ll a, ll b, vvec & RDP)
{
    cout << "[A] " << a << " ";
    while(RDP[a][0] != 0)
    {
        a = RDP[a][0];
        cout << a << " ";
    } 
    cout << "\n";
    cout << "[B] " << b << " ";
    while(RDP[b][0] != 0)
    {
        b = RDP[b][0];
        cout << b << " ";
    } 
    cout << "\n";
}
void DualDistance(vvec &G, int n, int q)
{
    vec S(n+1, 0), P(n+1, 0), C(n+1, 0), T(n+1, 0), L(n+1, 0);
    ump ctDP, Cdp;
    first(1, 0, G, S, P, C, L, 1);

    T[0] = S[1] + C[1];
    second(1, 0, G, T, S, C, ctDP, Cdp, n);
    vvec RDP(n+1, vec(20, 0));

    for(int nod=1; nod<=n; nod++) 
    RDP[nod][0] = P[nod];

    for(int j=1; j<20; j++)
        for(int nod=1; nod<=n; nod++)
        RDP[nod][j] = RDP[RDP[nod][j-1]][j-1];

    vector<ll> v(4, 0);
    ll a, b, ans=0;

    while(q--)
    {
        cin>>a>>b;
        if (L[a] < L[b]) swap(a, b);
        MidProps(a, b, RDP, L, v);

        ll m1 = v[0], m2 = v[1], da=v[2], db=v[3];
        ll ct1 = T[a] - (da+1)*Cdp[{m1, m2}] - ctDP[{m1, m2}];
        ll ct2 = T[b] - (db+1)*Cdp[{m2, m1}] - ctDP[{m2, m1}];
        ans = ct1 + ct2;
        cout <<ans << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);  
    cin.tie(NULL);

    int t; 
    cin>>t;
    ll n, q;

    while(t--)
    {
        cin>>n>>q;
        vvec G(n+1);
        ll u, v;
        for(int i=1; i<n; i++)
        {
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        DualDistance(G, n, q);
    }
    return 0;
}