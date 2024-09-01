// Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: shortest-distance-after-road-addition-queries-i
 *  RUNTIME: 178 ms
 *  MEMORY: 45.7 MB
 *  DATE: 8-7-2024, 12:04:50 PM
 *
 */

// Solution:

class Solution {
    
    private int bellmanFordHelper(List<List<Integer>> list) {
        int n = list.size();
        
        int[] distance = new int[n];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[0] = 0;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);

        while (!queue.isEmpty()) {
            int u = queue.poll();
            for (int v : list.get(u)) {
                if (distance[u] + 1 < distance[v]) {
                    distance[v] = distance[u] + 1;
                    queue.add(v);
                }
            }
        }

        return distance[n - 1];
    }
    
    
    public int[] shortestDistanceAfterQueries(int n, int[][] queries) {
        List<List<Integer>> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            list.add(new ArrayList<>());
        }
        for (int i = 0; i < n - 1; i++) {
            list.get(i).add(i + 1);
        }
        
        int[] res = new int[queries.length];
        int i=0;
        for (int[] query:queries) {
            list.get(query[0]).add(query[1]);
            res[i++] = bellmanFordHelper(list);
        }

        return res;
    }
}
