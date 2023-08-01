// Link: https://leetcode.com/problems/minimum-average-difference

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-average-difference
 *  RUNTIME: 336 ms
 *  MEMORY: 78.4 MB
 *  DATE: 12-4-2022, 6:07:19 PM
 *
 */

// Solution:

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int ans = -1;
        int mini = INT_MAX;
        long long currSum = 0;
        long long total = 0;
        for(auto i:nums)
            total += i;

        long long avg = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            currSum += nums[i];

            if(i == n-1)
                avg = currSum/n;
            else
                avg = abs((currSum / (i+1)) - ((total-currSum) / (n-i-1)));
            if (avg < mini)
            {
                mini = avg;
                ans = i;
            }
        }
        return ans;
    }
};
