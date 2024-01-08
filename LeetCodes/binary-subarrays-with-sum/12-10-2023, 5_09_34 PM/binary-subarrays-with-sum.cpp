// Link: https://leetcode.com/problems/binary-subarrays-with-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: binary-subarrays-with-sum
 *  RUNTIME: 1204 ms
 *  MEMORY: 29.1 MB
 *  DATE: 12-10-2023, 5:09:34 PM
 *
 */

// Solution:

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int left=0;
        int right=0;
        int count=0;
        int sum=0;
        while(right<nums.size())
        {
            sum+=nums[right];
            while(left<right && sum>goal)
            {
                sum-=nums[left];
                left+=1;
            }
            if(sum==goal)
            {
                int temp=left;
                while(temp<right && nums[temp]==0)
                {
                    temp+=1;
                    count+=1;
                }
                count+=1;
            }
            right+=1;
        }
        return count;
    }
};
