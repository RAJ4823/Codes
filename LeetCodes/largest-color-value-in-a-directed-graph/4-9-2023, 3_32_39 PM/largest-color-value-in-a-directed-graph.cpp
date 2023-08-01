// Link: https://leetcode.com/problems/largest-color-value-in-a-directed-graph

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: largest-color-value-in-a-directed-graph
 *  RUNTIME: 641 ms
 *  MEMORY: 174.5 MB
 *  DATE: 4-9-2023, 3:32:39 PM
 *
 */

// Solution:

class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<vector<int>> graph(colors.size()), cnt(colors.size(), vector<int>(26));
        vector<int> ind(colors.size());
        for (auto &e: edges) {
            graph[e[0]].push_back(e[1]);
            ind[e[1]]++;
        }

        vector<int> q;
        for (int i = 0; i < colors.size(); ++i) {
            if (ind[i] == 0)
                q.push_back(i);
        }

        int ans = 0, temp = 0;
        while (!q.empty()) {
            vector<int> q1;
            for (auto i : q) {
                temp++;
                ans = max(ans, ++cnt[i][colors[i] - 'a']);
                
                for (auto j : graph[i]) {
                    for (auto k = 0; k < 26; ++k)
                        cnt[j][k] = max(cnt[j][k], cnt[i][k]);
                    if (--ind[j] == 0)
                        q1.push_back(j);
                }
            }
            swap(q, q1);
        }
        if(temp == colors.size()) 
            return ans;
        return -1;
    }
};
