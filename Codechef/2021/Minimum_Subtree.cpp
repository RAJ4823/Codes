/*
    Made By : Raj Patel
    Date : 14/6/2021
*/

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define vec vector<int>
#define vvec vector<vector<int>>

int getAns(int node, vvec & G, int n)
{
  vector<bool> final(n+1, false);
  int fd=-1, ans;  
  final[node] = true;
  queue<pair<int, int>> q; q.push({node, 0});

  while(q.size())
  {
    auto p = q.front(); q.pop();
    int nod = p.first, dis = p.second;

    if(fd < dis) fd = dis, ans = nod;

    for(auto NOD: G[nod])
    {
      if(final[NOD]) 
        continue;

      final[NOD] = true;
      q.push({NOD, dis+1});
    }
  }
  return ans;
}

void calc(int nod, int par, vvec & G, vec & H, vec & li, int cur)
{
    bool isleaf = true;
    int mx = 0;

    for(auto NOD: G[nod]) if(NOD != par) 
    {
        isleaf = false; 
        mx = max(mx, H[NOD]);
    }

    if(isleaf)
    { 
        li.push_back(cur); 
        return; 
    }

    int c = 0;
    for(auto NOD: G[nod]){
        if(NOD == par) continue;
        if(H[NOD] == mx && c==0){
        calc(NOD, nod, G, H, li, cur+1); c++;
        }
        else calc(NOD, nod, G, H, li, 1);
    }
}

void FIX(int nod, int par, vvec & G, vec & H)
{
    bool isleaf = true;
    for(auto NOD: G[nod])
    {
        if(NOD == par) continue;
        isleaf = false;
        FIX(NOD, nod, G, H);
        H[nod] = max(H[nod], 1 + H[NOD]);
    }
    if(isleaf) H[nod] = 1;
}

void lines(int nod, int par, vvec & G, vec&li, int n)
{
    vector<int> H(n+1, 0);
    FIX(nod, par, G, H);
    calc(nod, par, G, H, li, 1);    
}

int Sol(vvec & vr, int n, int k)
{
    if(k==1) 
    return 1;

    int u = getAns(1, vr, n);
    vector<int> li;

    lines(u, 0, vr, li, n);

    sort(li.rbegin(), li.rend());
    int size = 1, total = 0, i = 0;

    while(total < k)
    {
        size++; total += li[i++];
    }
    return size;
}

void solve()
{
     int n, k;
     int u, v;
     
    cin>>n>>k;
    vvec vr(n+1);
    
    for(int i=1; i<n; i++)
    {
      cin>>u>>v;
      vr[u].push_back(v); 
      vr[v].push_back(u);
    }
    cout << Sol(vr, n, k) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int t;
    cin>>t;
    int _=1;

    while(t--)
    {
        solve();
    }
    return 0;
}