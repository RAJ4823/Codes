// Link: https://leetcode.com/problems/restore-the-array-from-adjacent-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: restore-the-array-from-adjacent-pairs
 *  RUNTIME: 298 ms
 *  MEMORY: 141 MB
 *  DATE: 11-10-2023, 11:33:13 AM
 *
 */

// Solution:

class Solution {
public:
    void find(int source, int parent, vector<int> &arr, unordered_map<int, vector<int>> &adj) {
        arr.push_back(source);
        for(auto &next: adj[source]) {
            if(next != parent) {
                find(next, source, arr, adj);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adj;
        for(auto &pair: pairs) {
            adj[pair[0]].push_back(pair[1]);
            adj[pair[1]].push_back(pair[0]);
        }

        int source = 0;
        for(auto &[val, neighbours]: adj) {
            if(neighbours.size() == 1) {
                source = val;
                break;
            }
        }
        
        vector<int> arr;
        find(source, source, arr, adj);
        return arr;
    }
};
