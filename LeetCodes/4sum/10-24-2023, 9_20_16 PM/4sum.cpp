// Link: https://leetcode.com/problems/4sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: 4sum
 *  RUNTIME: 57 ms
 *  MEMORY: 13.5 MB
 *  DATE: 10-24-2023, 9:20:16 PM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();

        for(int l=0; l<n-2; l++) {
            //3SUM
            for(int i=l+1; i<n-1; i++) {
                int j = i+1, k = n - 1;
                while(j < k) {
                    ll sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[k] + (ll)nums[l];
                    if(sum == target) {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        int left = j, right = k;
                        while(j < k && nums[j] == nums[left]) j++;
                        while(j < k && nums[k] == nums[right]) k--;
                    } else if(sum < target) {
                        j++;
                    } else {
                        k--;
                    }
                }
                while(i+1 < n && nums[i] == nums[i+1]) i++;
            }
            while(l+1 < n && nums[l] == nums[l+1]) l++;
        }
        return ans;
    }
};
