//? https://leetcode.com/problems/making-a-large-island/description/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> par, size;
    DisjointSet(int n)
    {
        size.resize(n, 1);
        par.resize(n);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }

    int findPar(int x)
    {
        if (x == par[x])
            return x;
        return par[x] = findPar(par[x]);
    }

    void unionBySize(int x, int y)
    {
        int px = findPar(x);
        int py = findPar(y);

        if (px == py)
            return;
        if (size[px] < size[py])
        {
            par[px] = py;
            size[py] += size[px];
        }
        else
        {
            par[py] = px;
            size[px] += size[py];
        }
    }
};

class Solution {
public:
    int dirs[5] = {-1,0,1,0,-1};
    bool isValid(int row, int col, int n) {
        if(row < 0 || col < 0 || row >= n || col >= n)
            return false;
        return true;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> z; // coords of zeroes
        DisjointSet ds(n*n);

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 0) {
                    z.push({i, j});
                    continue;
                }

                for(int k=0; k<4; k++) {
                    int row = i + dirs[k];
                    int col = j + dirs[k+1];

                    if(isValid(row, col, n) && grid[row][col] == 1) {
                        int currNode = i*n + j;
                        int nextNode = row*n + col;
                        ds.unionBySize(currNode, nextNode);     
                    }
                }
            }
        }

        int ans = 0;
        for(int node = 0; node < n*n; node++) {
            ans = max(ans, ds.size[ds.findPar(node)]);
        }

        while(!z.empty()) {
            int i = z.front().first;
            int j = z.front().second;
            z.pop();

            set<int> s;
            int totalSize = 0;
            
            for(int k=0; k<4; k++) {
                int row = i + dirs[k];
                int col = j + dirs[k+1];

                if(isValid(row, col, n) && grid[row][col] == 1) {
                    int nextNode = row*n + col;
                    s.insert(ds.findPar(nextNode));    
                }
            }
            for(auto &x: s) {
                totalSize += ds.size[x];  
            } 
            ans = max(ans, totalSize+1);
            
        }
        return ans;
    }
};