// Link: https://leetcode.com/problems/two-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: two-sum
 *  RUNTIME: 368 ms
 *  MEMORY: 10.3 MB
 *  DATE: 12-6-2022, 1:45:13 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2);
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {   
                if(nums[i] + nums[j] == target)
                {
                    ans[0] = i;
                    ans[1] = j; 
                }
            }
        }
        return ans;
    }
};
