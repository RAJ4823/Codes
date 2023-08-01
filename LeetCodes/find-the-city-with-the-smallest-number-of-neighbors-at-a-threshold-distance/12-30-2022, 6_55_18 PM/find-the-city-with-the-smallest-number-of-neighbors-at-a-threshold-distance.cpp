// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance
 *  RUNTIME: 133 ms
 *  MEMORY: 12.1 MB
 *  DATE: 12-30-2022, 6:55:18 PM
 *
 */

// Solution:

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int maxDist) {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        for (auto &data : edges)
        {
            int u = data[0];
            int v = data[1];
            int w = data[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == 1e9 || dist[k][j] == 1e9)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int city = -1;
        int minCount = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] <= maxDist)
                    count++;
            }

            if (count <= minCount)
            {
                city = i;
                minCount = count;
            }
        }
        return city;
    }
};
