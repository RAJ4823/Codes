// Link: https://leetcode.com/problems/arithmetic-subarrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: arithmetic-subarrays
 *  RUNTIME: 109 ms
 *  MEMORY: 38.7 MB
 *  DATE: 3-21-2023, 9:10:04 AM
 *
 */

// Solution:

class Solution {
public:
    bool check(int l, int r, vector<int> &nums) {
        if(r-l == 1) return true;
        vector<int> temp;
        for(int i=l; i<=r; i++) {
            temp.push_back(nums[i]);
        }
        sort(temp.begin(), temp.end());
        int diff = temp[1] - temp[0];
        for(int i=1; i<temp.size()-1; i++) {
            if(temp[i+1] - temp[i] != diff)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = l.size();
        vector<bool> ans(m, false);

        for(int i=0;i<m; i++) {
            if(check(l[i], r[i], nums)) {
                ans[i] = true;
            }
        }
        return ans;
    }
};
