// Link: https://leetcode.com/problems/permutations-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: permutations-ii
 *  RUNTIME: 40 ms
 *  MEMORY: 9.1 MB
 *  DATE: 8-1-2023, 10:09:47 AM
 *
 */

// Solution:

class Solution {
public:
    set<vector<int>> s;

    void find(int mask, int &n, vector<int> &arr, vector<int> &nums) {
        if(mask == ((1 << n) - 1)) {
            s.insert(arr);
            return;
        }
        for(int i=0; i<n; i++) {
            if((mask & (1 << i)) == 0) {
                arr.push_back(nums[i]);
                find((mask | (1 << i)), n, arr, nums);
                arr.pop_back();
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        find(0, n, arr, nums);
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;

    }
};
