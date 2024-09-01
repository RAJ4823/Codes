// Link: https://leetcode.com/problems/path-with-maximum-probability

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: path-with-maximum-probability
 *  RUNTIME: 28 ms
 *  MEMORY: 58.2 MB
 *  DATE: 8-31-2024, 11:12:58 AM
 *
 */

// Solution:

class Solution {
    public double maxProbability(int n, int[][] edges, double[] succProb, int start_node, int end_node) {
        List<double[]>[] adj = new List[n];
        for(int i=0; i<n; i++) adj[i] = new ArrayList<>();
            
        for(int i=0; i<succProb.length; i++) {
            int[] edge = edges[i];
            adj[edge[0]].add(new double[]{edge[1], succProb[i]});
            adj[edge[1]].add(new double[]{edge[0], succProb[i]});
        }

        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[1], a[1]));
        double[] maxProb = new double[n];
        boolean[] vis = new boolean[n];
        pq.add(new double[]{start_node, 1.0});

        while(!pq.isEmpty()) {
            double[] curr = pq.remove();
            int currNode = (int) curr[0];
            double currProb = curr[1];
            vis[currNode] = true;

            if(currNode == end_node) {
                return maxProb[end_node];
            }

            for(double[] next: adj[currNode]) {
                int nextNode = (int) next[0];
                double nextProb = next[1];

                if(!vis[nextNode] && nextProb * currProb > maxProb[nextNode]) {
                    maxProb[nextNode] = nextProb * currProb;
                    pq.add(new double[]{nextNode, maxProb[nextNode]});
                }
            }
        }

        return maxProb[end_node];   
    }
}
