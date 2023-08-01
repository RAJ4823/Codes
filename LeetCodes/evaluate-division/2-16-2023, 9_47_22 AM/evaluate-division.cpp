// Link: https://leetcode.com/problems/evaluate-division

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: evaluate-division
 *  RUNTIME: 0 ms
 *  MEMORY: 8.2 MB
 *  DATE: 2-16-2023, 9:47:22 AM
 *
 */

// Solution:

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        int i = 0;
        unordered_map<string, int> m;

        //Converting string to nums
        for (auto e : equations)
        {
            if (m.find(e[0]) == m.end())    m[e[0]] = i++;
            if (m.find(e[1]) == m.end())    m[e[1]] = i++;
        }

        int len = m.size();
        vector<double> ans;
        vector<vector<double>> graph(len, vector<double>(len, -1));
        for (int i = 0; i < equations.size(); i++)
        {
            int u = m[equations[i][0]];
            int v = m[equations[i][1]];
            graph[u][v] = values[i];
            graph[v][u] = 1 / values[i];
        }
        int n = graph.size();
        for(int i=0; i<n;i++)
            graph[i][i] = 1;

        // Floyd Warshall Algo
        for (int k = 0; k < n; k++) 
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (graph[i][k] == -1 || graph[k][j] == -1)
                        continue;
                    if (graph[i][j] == -1)
                        graph[i][j] = graph[i][k] * graph[k][j];
                    else
                        graph[i][j] = min(graph[i][j], graph[i][k] * graph[k][j]);
                }
            }
        }

        for (auto q : queries)
        {
            if (m.find(q[0]) == m.end() || m.find(q[1]) == m.end())
            {
                ans.push_back(-1);
                continue;
            }

            int u = m[q[0]];
            int v = m[q[1]];
            if (graph[u][v] != -1)
                ans.push_back(graph[u][v]);
            else
            {
                if (graph[v][u] != -1)
                    ans.push_back(1 / graph[v][u]);
                else
                    ans.push_back(-1);
            }
        }
        return ans;
    }
};
