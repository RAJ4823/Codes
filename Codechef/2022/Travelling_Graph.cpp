#include <bits/stdc++.h>
using namespace std;
void dfs(int p,vector<vector<int>> &v,vector<bool>&vis,int &mx){
    if(v[p].size()==0 || vis[p]==true) return;
    
    mx = max(mx,p);
    
    for(int i=0;i<v[p].size();i++){
        vis[p] = true;
        int x = v[p][i];
        mx = max(mx,x);
        dfs(v[p][i],v,vis,mx);
    }
    
}
int minCost(int n,int m,vector<vector<int>> &v){
    int cost = 0;
    if(m==0){
        return n-1;
    }
    int k=1;
    vector<bool> vis(n,false);
    dfs(k,v,vis,k);
    cost = (n-k);
    return cost;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> bidir(n+1,vector<int>(0,0));
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            bidir[a].push_back(b);
            bidir[b].push_back(a);
        }
        cout<< minCost(n,m, bidir)<<"\n";
    }
    
  return 0;
}