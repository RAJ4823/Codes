// Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: most-stones-removed-with-same-row-or-column
 *  RUNTIME: 13 ms
 *  MEMORY: 44.7 MB
 *  DATE: 8-29-2024, 9:49:35 AM
 *
 */

// Solution:

class DisjointSet {
    int[] par, size;
    DisjointSet(int n) {
        par = new int[n];
        size = new int[n];
        for(int i=0; i<n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int x) {
        if(par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    void merge(int x, int y) {
        int px = findPar(x);
        int py = findPar(y);

        if(px == py) return;

        if(size[px] <= size[py]) {
            par[px] = py;
            size[py] += size[px]; 
        } else {
            par[py] = par[px];
            size[px] += size[py];
        }
    }
}

class Solution {
    int MAX = 10001;
    public int removeStones(int[][] stones) {
        int n = stones.length;
        int totalNodesCount = MAX * 2;
        DisjointSet ds = new DisjointSet(totalNodesCount);
        Set<Integer> existingNodes = new HashSet<>();

        for(int i=0; i<n; i++) {
            int row = stones[i][0];
            int col = stones[i][1] + MAX;
            ds.merge(row, col);
            existingNodes.add(row);
            existingNodes.add(col);
        }

        int count = 0;
        for(int node: existingNodes) {
            if(ds.findPar(node) == node) {
                count++;
            }
        }
        return n - count;
    }
}
