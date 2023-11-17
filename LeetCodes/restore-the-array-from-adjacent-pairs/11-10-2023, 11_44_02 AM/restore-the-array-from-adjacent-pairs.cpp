// Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: restore-the-array-from-adjacent-pairs
 *  RUNTIME: 294 ms
 *  MEMORY: 105.7 MB
 *  DATE: 11-10-2023, 11:44:02 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        for(auto &pair: pairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        int source = 0, parent = -1e9;
        for(auto &[val, neighbours]: adj) {
            if(neighbours.size() == 1) {
                source = val;
                break;
            }
        }
        
        vector<int> arr;
        arr.push_back(source);
        while(arr.size() < adj.size()) {
            int next = (adj[source][0] == parent) ? adj[source][1] : adj[source][0];
            arr.push_back(next);
            parent = source;
            source = next;
        }
        return arr;
    }
};
