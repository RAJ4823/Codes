// Link: https://leetcode.com/problems/minimum-height-trees

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-height-trees
 *  RUNTIME: 23 ms
 *  MEMORY: 57.3 MB
 *  DATE: 4-23-2024, 3:54:51 PM
 *
 */

// Solution:

class Solution {
    public List<Integer> findMinHeightTrees(int n, int[][] edges) {
        List<Integer> ans = new ArrayList<>();
        if(n == 1) {
            ans.add(0);
            return ans;
        }

        Map<Integer, List<Integer>> adj = new HashMap<>();
        int ind[] = new int[n];

        for(int[] edge: edges) {
            ind[edge[0]]++;
            ind[edge[1]]++;

            adj.putIfAbsent(edge[0], new ArrayList());
            adj.putIfAbsent(edge[1], new ArrayList());

            adj.get(edge[0]).add(edge[1]);
            adj.get(edge[1]).add(edge[0]);
        }

        Queue<Integer> q = new LinkedList();
        for(int i=0; i<ind.length; i++) {
            if(ind[i] == 1) {
                q.add(i);
            }
        }

        int count = 0;
        while(n - count > 2) {
            int size = q.size();
            count += size;

            while(size > 0) {
                int node = q.remove();
                for(int next: adj.get(node)) {
                    ind[next]--;
                    if(ind[next] == 1) {
                        q.add(next);
                    }
                }

                size--;
            }
        }

        ans.addAll(q);
        return ans;
    }
}
