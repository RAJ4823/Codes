// Link: https://leetcode.com/problems/two-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: two-sum
 *  RUNTIME: 15 ms
 *  MEMORY: 10.7 MB
 *  DATE: 12-6-2022, 1:49:32 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++)
        {
            if(m.find(target - nums[i]) != m.end())
            {
                ans[0] = i;
                ans[1] = m[target - nums[i]];
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};
