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
#define MOD 1000000007LL

int main()
{
    int q;
    cin>>q;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    queue<int> que;
    unordered_map<int, bool> vis;
    int i = 1;
    while(q--)
    {
        int k;
        cin >> k;
        if(k == 1) {
            int m;
            cin >> m;
            que.push(i);
            pq.push({m, i++});
        } else {
            if(k == 2) {
                while(vis[que.front()]) {
                    que.pop();
                }
                int inx = que.front();
                que.pop();
                cout << inx << ' ';
            } else {
                while(vis[pq.top().second]) {
                    pq.pop();
                }
                int inx = pq.top().second;
                pq.pop();
                vis[inx] = true;
                cout << inx << ' ';
            }
        }  
    }
    return 0;
}