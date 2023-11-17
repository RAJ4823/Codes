// Link: https://leetcode.com/problems/3sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: 3sum
 *  RUNTIME: 104 ms
 *  MEMORY: 24.4 MB
 *  DATE: 10-24-2023, 9:07:36 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++) {
            int j = i+1, k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    int left = j, right = k;
                    while(j < k && nums[j] == nums[left]) j++;
                    while(j < k && nums[k] == nums[right]) k--;
                } else if(sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};
