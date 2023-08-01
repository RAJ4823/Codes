// Link: https://leetcode.com/problems/evaluate-division

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: evaluate-division
 *  RUNTIME: 3 ms
 *  MEMORY: 8.2 MB
 *  DATE: 5-20-2023, 9:51:54 AM
 *
 */

// Solution:

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, int> in;
        int index=0;
        for(auto &e: equations) {
            if(in.find(e[0]) == in.end())
                in[e[0]] = index++;
            if(in.find(e[1]) == in.end())
                in[e[1]] = index++;
        }

        int n = in.size();
        int m = equations.size();
        vector<vector<double>> graph(n, vector<double> (n, -1));
        vector<double> ans;

        for(int i=0; i<m; i++) {
            int u = in[equations[i][0]];
            int v = in[equations[i][1]];
            graph[u][v] = values[i];
            graph[v][u] = 1/values[i];
        }
        for(int i=0; i<n; i++) {
            graph[i][i] = 1;
        }

        for(int k=0;k<n; k++) {
            for(int i=0; i<n; i++) {
                for(int j=0; j<n; j++) {
                    if (graph[i][k] == -1 || graph[k][j] == -1)
                        continue;
                    if (graph[i][j] == -1)
                        graph[i][j] = graph[i][k] * graph[k][j];
                    else
                        graph[i][j] = min(graph[i][j], graph[i][k] * graph[k][j]);
                }
            }
        }

        for(auto &q: queries) {
            if(in.find(q[0]) == in.end() || in.find(q[1]) == in.end()) {
                ans.push_back(-1);
                continue;
            }

            int u = in[q[0]];
            int v = in[q[1]];
            ans.push_back(max(graph[u][v], 1 / graph[v][u]));
        }
        return ans;
    }
};
