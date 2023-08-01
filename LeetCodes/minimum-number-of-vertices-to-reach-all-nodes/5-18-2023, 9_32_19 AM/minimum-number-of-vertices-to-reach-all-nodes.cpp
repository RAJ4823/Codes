// Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-vertices-to-reach-all-nodes
 *  RUNTIME: 317 ms
 *  MEMORY: 94.2 MB
 *  DATE: 5-18-2023, 9:32:19 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ind(n, 0);
        for(auto &edge: edges) {
            ind[edge[1]]++;
        }
        
        vector<int> ans;
        for(int i=0; i<n; i++) {
            if(ind[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
