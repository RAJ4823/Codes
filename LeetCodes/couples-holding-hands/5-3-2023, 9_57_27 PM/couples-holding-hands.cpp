// Link: https://leetcode.com/problems/couples-holding-hands

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: couples-holding-hands
 *  RUNTIME: 0 ms
 *  MEMORY: 7.4 MB
 *  DATE: 5-3-2023, 9:57:27 PM
 *
 */

// Solution:



class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findPar(int x)
    {
        if(x==parent[x])    return x;
        return parent[x] = findPar(parent[x]);
    }
    bool Union(int x,int y)
    {
        int px=findPar(x);
        int py=findPar(y);
        if(px == py) return true;

        if(size[px]>=size[py])
        {
            parent[py]=px;
            size[px]+=size[py];
        }
        else 
        {
            parent[px]=py;
            size[py]+=size[px];
        }
        return false;
    }
    
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
      DisjointSet ds(row.size());
      for(int i=0;i<row.size();i+=2)
      {
          ds.Union(row[i],row[i+1]);
      }
      int cnt=0;
      for(int i=0;i<row.size();i+=2)
      {
          if(!ds.Union(i, i+1))
              cnt++;
      }
      return cnt;
    }
};
