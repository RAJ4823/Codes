// Link: https://leetcode.com/problems/minimum-absolute-difference

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-absolute-difference
 *  RUNTIME: 61 ms
 *  MEMORY: 32.2 MB
 *  DATE: 8-9-2023, 12:43:42 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), minDiff = INT_MAX;
        for(int i=0; i<n-1; i++) {
            minDiff = min(minDiff, arr[i+1] - arr[i]);
        }
        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++) {
            if(arr[i+1] - arr[i] == minDiff) {
                ans.push_back({arr[i], arr[i+1]});
            }
        }
        return ans;
    }
};
