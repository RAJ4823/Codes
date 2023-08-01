// Link: https://leetcode.com/problems/all-paths-from-source-to-target

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: all-paths-from-source-to-target
 *  RUNTIME: 29 ms
 *  MEMORY: 10.7 MB
 *  DATE: 5-27-2022, 5:21:32 PM
 *
 */

// Solution:

class Solution {
public:
    void dfs(int s, vector<int> &temp, vector<vector<int>> &graph, vector<vector<int>> &paths)
    {
        temp.push_back(s);
        if(s == graph.size()-1)
        {
            paths.push_back(temp);
        }
        for(auto i : graph[s])
            dfs(i, temp, graph, paths);
        temp.pop_back();
        
}
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> temp;
        dfs(0, temp, graph, paths);
        return paths;
    }
};
