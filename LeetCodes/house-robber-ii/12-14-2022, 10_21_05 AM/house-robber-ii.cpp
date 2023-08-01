// Link: https://leetcode.com/problems/house-robber-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: house-robber-ii
 *  RUNTIME: 5 ms
 *  MEMORY: 7.9 MB
 *  DATE: 12-14-2022, 10:21:05 AM
 *
 */

// Solution:

class Solution {
private:
    int find(int start, int end, vector<int>& nums) {
        int curr = 0;
        int prev1 = nums[start];
        int prev2 = 0;
   
        for(int i=start+1; i<=end; i++)
        {
            curr = max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0], nums[1]);
        return max(find(0,n-2,nums), find(1,n-1,nums));
    }
};
