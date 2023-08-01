// Link: https://leetcode.com/problems/min-cost-to-connect-all-points

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: min-cost-to-connect-all-points
 *  RUNTIME: 82 ms
 *  MEMORY: 10.2 MB
 *  DATE: 3-25-2023, 10:53:00 AM
 *
 */

// Solution:

class Solution {
public:
	int minCostConnectPoints(vector<vector<int>> &points) {
		int ans = 0, n = points.size();

		vector<int> minCost(n, INT_MAX); minCost[0] = 0;
		vector<int> vis(n);

		int i = 0;
		while (i >= 0) {
			vis[i] = true;

			int mini = INT_MAX;
			int next = -1;
			for (int j = 0; j < n; j++) {
				if (vis[j] || j == i)
					continue;

                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
				minCost[j] = min(dist, minCost[j]);
				if (minCost[j] < mini) {
					mini = minCost[j];
					next = j;
				}
			}
            if(mini != INT_MAX)
                ans += mini;
			i = next;
		}
		return ans;
    }
};
