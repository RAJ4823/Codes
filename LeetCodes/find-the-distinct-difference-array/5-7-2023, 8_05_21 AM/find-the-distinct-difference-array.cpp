// Link: https://leetcode.com/problems/find-the-distinct-difference-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-distinct-difference-array
 *  RUNTIME: 83 ms
 *  MEMORY: 93.8 MB
 *  DATE: 5-7-2023, 8:05:21 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        unordered_map<int,int> right, left;
        int n = nums.size();
        vector<int> cr(n+1, 0), cl(n+1, 0);
        
        for(int i=0; i<n; i++) {
            right[nums[i]]++;
            cr[i] = right.size();
        }
        for(int i=n-1; i>=0; i--) {
            left[nums[i]]++;
            cl[i] = left.size();
        }
        
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            ans[i] = (cr[i] - cl[i+1]);
        }
        return ans;
    }
};
