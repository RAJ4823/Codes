// Link: https://leetcode.com/problems/arithmetic-subarrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: arithmetic-subarrays
 *  RUNTIME: 174 ms
 *  MEMORY: 76 MB
 *  DATE: 11-23-2023, 5:00:48 PM
 *
 */

// Solution:

class Solution {
public:
    bool check(int i, int j, vector<int> &nums) {
        int mini = INT_MAX, maxi = INT_MIN;
        unordered_set<int> st;
        for(int k=i; k<=j; k++) {
            st.insert(nums[k]);
            mini = min(mini, nums[k]);
            maxi = max(maxi, nums[k]);
        }

        int diff = (maxi - mini) / (j - i);
        int rem = (maxi - mini) % (j - i);
        if(rem != 0) {
            return false;
        }

        int x = mini + diff;
        while(x < maxi) {
            if(!st.count(x))
                return false;
            x += diff;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i=0; i<l.size(); i++) {
            ans.push_back(check(l[i], r[i], nums));
        }
        return ans;
    }
};
