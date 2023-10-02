// Link: https://leetcode.com/problems/count-valid-paths-in-a-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: count-valid-paths-in-a-tree
 *  RUNTIME: 408 ms
 *  MEMORY: 172.9 MB
 *  DATE: 9-27-2023, 5:49:07 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    vector<bool> isPrime;
    vector<vector<int>> graph;
    ll ans = 0;
    
    void fillPrimes(int n) {
        isPrime.resize(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        
        for(int i=2; i * i<n; i++) {
            if(isPrime[i]) {
                for(int j=i*i; j<n; j+=i) {
                    isPrime[j] = false;
                }
            }
        }
    }
    
    pair<ll,ll> dfs(int curr, int parent) {
        ll currZero = !isPrime[curr];
        ll currOne = isPrime[curr];
        
        for(auto &next: graph[curr]) {
            if(next == parent) continue;
            
            const auto &[childZero, childOne] = dfs(next, curr); 
            ans += (currZero * childOne) + (currOne * childZero);
            
            if(isPrime[curr]) {
                currOne += childZero;
            } else {
                currOne += childOne;
                currZero += childZero;
            }
        }
        
        return {currZero, currOne};
    }
    
    long long countPaths(int n, vector<vector<int>>& edges) {
        fillPrimes(n + 1);
        graph.resize(n + 1);
        for(auto &edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        dfs(1, -1);
        return ans;
    }
};
