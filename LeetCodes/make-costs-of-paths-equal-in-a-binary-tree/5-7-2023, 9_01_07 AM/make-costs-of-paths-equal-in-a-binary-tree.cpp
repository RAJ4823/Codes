// Link: https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: make-costs-of-paths-equal-in-a-binary-tree
 *  RUNTIME: 306 ms
 *  MEMORY: 140.2 MB
 *  DATE: 5-7-2023, 9:01:07 AM
 *
 */

// Solution:

class Solution
{
public:
    vector<int> path;
    int n;
    int maxi;

    void dfs_fill(int i, int val, vector<int> &cost)
    {
        if (i >= n)
            return;
        path[i] = cost[i] + val;

        int left = 2 * i + 1;
        int right = 2 * i + 2;

        dfs_fill(left, path[i], cost);
        dfs_fill(right, path[i], cost);
    }

    int find(int left, int right, int maxi)
    {
        if(left <= right) {
            int curr = *max_element(path.begin() + left, path.begin() + right + 1);
            int ans = maxi - curr;

            for (int i = left; i <= right; i++)
            {
                path[i] += maxi - curr;
            }

            if (left != right)
            {
                int mid = (left + right) / 2;
                ans = ans + find(left, mid, maxi) + find(mid + 1, right, maxi);
            }
            return ans;
        }
        return 0;
    }

    void setMaxi()
    {
        maxi = *max_element(path.begin() + n / 2, path.end());
    }

    void init(int N, vector<int> &cost)
    {
        n = N;
        path.resize(n, 0);
        dfs_fill(0, 0, cost);
        setMaxi();
    }

    int minIncrements(int N, vector<int> &cost)
    {
        init(N, cost);
        return find(n / 2, n - 1, maxi);
    }
};
