// Link: https://leetcode.com/problems/merge-similar-items

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: merge-similar-items
 *  RUNTIME: 18 ms
 *  MEMORY: 17.4 MB
 *  DATE: 12-10-2023, 5:04:54 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> sums;
        for(auto &x: items1) sums[x[0]] += x[1];
        for(auto &x: items2) sums[x[0]] += x[1];
        vector<vector<int>> ans;
        
        for(auto &[val, weight]: sums) {
            ans.push_back({val, weight});
        }
        return ans;
    }
};
