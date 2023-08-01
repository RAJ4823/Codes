// Link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: merge-two-2d-arrays-by-summing-values
 *  RUNTIME: 7 ms
 *  MEMORY: 10.6 MB
 *  DATE: 2-19-2023, 8:06:14 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& a, vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int n = a.size(), i =0;
        int m = b.size(), j =0;
        
        while(i < n && j < m) {
            if(a[i][0] == b[j][0]) {
                ans.push_back({a[i][0], a[i][1] + b[j][1]});
                i++;
                j++;
            } else if(a[i][0] < b[j][0]) {
                ans.push_back({a[i][0], a[i][1]});
                i++;
            } else {
                ans.push_back({b[j][0], b[j][1]});
                j++;
            }
        }
        while(i < n) {
            ans.push_back({a[i][0], a[i][1]});
            i++;
        }
        while(j < m) {
            ans.push_back({b[j][0], b[j][1]});
            j++;;
        }
        return ans;
    }
};
