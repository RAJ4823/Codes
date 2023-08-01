// Link: https://leetcode.com/problems/sum-of-distances-in-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sum-of-distances-in-tree
 *  RUNTIME: 272 ms
 *  MEMORY: 84.3 MB
 *  DATE: 12-22-2022, 2:54:27 PM
 *
 */

// Solution:

#define vi vector<int>

class Solution {
private:
    void dfs_root(int root, int parent, vi tree[], vi &count, vi &ans) {
        for(auto &child: tree[root]) {
            if(child != parent) {
                dfs_root(child, root, tree, count, ans);

                count[root] += count[child];
                ans[root] += ans[child] + count[child];
            }
        }
    }

    void dfs_child(int root, int parent, vi tree[], vi &count, vi &ans) {
        for(auto &child: tree[root]) {
            if(child != parent) {
                ans[child] = ans[root] + (count.size()) - (2 * count[child]);

                dfs_child(child, root, tree, count, ans);
            }
        }
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> tree[n], count(n, 1), ans(n, 0);
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        dfs_root(0, -1, tree, count, ans);
        dfs_child(0, -1, tree, count, ans);

        return ans;
    }
};
