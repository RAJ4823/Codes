// Link: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-items-by-groups-respecting-dependencies
 *  RUNTIME: 73 ms
 *  MEMORY: 43.8 MB
 *  DATE: 8-20-2023, 10:39:48 AM
 *
 */

// Solution:

class Solution {
public:
    void dfs(int curr, vector<int> &sorted, vector<vector<int>> &adj, vector<int> &deg) {
        sorted.push_back(curr);
        deg[curr]--;    // Mark visited

        for(auto &next: adj[curr]) {
            deg[next]--;
            if(deg[next] == 0) {
                dfs(next, sorted, adj, deg);
            }
        }
    }

    vector<int> dfs_sort(vector<vector<int>> &adj, vector<int> &deg, int size) {
        vector<int> sorted;
        for(int i=0; i<size; i++) {
            if(deg[i] == 0) {
                dfs(i, sorted, adj, deg);
            }
        }
        if(sorted.size() < deg.size())
            return {};
        return sorted;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        for(int i=0; i<n; i++) {
            if(group[i] == -1) group[i] = (m++);
        }

        vector<vector<int>> adj_group(m), adj_item(n);
        vector<int> deg_group(m, 0), deg_item(n, 0);

        for(int curr=0; curr<n; curr++) {
            int curr_group = group[curr];
            for(auto &prev: beforeItems[curr]) {
                int prev_group = group[prev];

                if(curr_group != prev_group) {
                    adj_group[prev_group].push_back(curr_group);    // prev_group -> curr_group
                    deg_group[curr_group]++;                        // Indegree of curr_group++
                }

                adj_item[prev].push_back(curr);     // prev_item -> curr_item
                deg_item[curr]++;                   // Indegree of curr_item++
            }
        }

        vector<int> sorted_group = dfs_sort(adj_group, deg_group, m);
        vector<int> sorted_item = dfs_sort(adj_item, deg_item, n);

        if(sorted_group.empty() || sorted_item.empty()) return {};

        vector<vector<int>> items_in(m);
        for(auto &item: sorted_item) 
            items_in[group[item]].push_back(item);
        
        vector<int> ans;
        for(auto &group: sorted_group) {
            for(auto &item: items_in[group]) {
                ans.push_back(item);
            }
        }

        return ans;
    }
};
