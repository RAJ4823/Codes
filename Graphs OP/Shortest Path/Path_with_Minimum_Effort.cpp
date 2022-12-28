//? https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1
//? https://leetcode.com/problems/path-with-minimum-effort/description/

#include <bits/stdc++.h>
using namespace std;

// TC = O(E logV) where E = n*m*4 and V = n*m so
//? TC = O(n*m*4*log(n*m))

class Solution
{
public:
    int MinimumEffort(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        // MinHeap PQ: {diff, {row, col}}
        priority_queue<pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq; 

        vector<vector<int>> effort(n, vector<int>(m, 1e9));

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        while (!pq.empty())
        {
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int diff = pq.top().first;
            pq.pop();

            if (row == n - 1 && col == m - 1)
                return diff;
            for (int k = 0; k < 4; k++)
            {
                int newr = row + dx[k];
                int newc = col + dy[k];
                if (newr >= 0 && newc >= 0 && newr < n && newc < m)
                {
                    // newEfforts will be the max of (previous diff and new diff)
                    int newDiff = abs(heights[newr][newc] - heights[row][col]);
                    int newEffort = max(diff, newDiff);
                    if (newEffort < effort[newr][newc])
                    {
                        effort[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> heights;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < m; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }

        Solution obj;
        cout << obj.MinimumEffort(heights) << "\n";
    }
    return 0;
}
// } Driver Code Ends