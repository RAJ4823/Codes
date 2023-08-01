// Link: https://leetcode.com/problems/minimum-average-difference

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-average-difference
 *  RUNTIME: 253 ms
 *  MEMORY: 78.3 MB
 *  DATE: 12-4-2022, 6:01:20 PM
 *
 */

// Solution:

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
         int n = nums.size();
        int ans = -1;
        int mini = INT_MAX;
        long long currSum = 0;

        long long total = 0;
        for (int i = 0; i < n; ++i)
            total += nums[i];

        for (int i = 0; i < n; ++i)
        {
            currSum += nums[i];
            long long avg1 = currSum / (i + 1);
            long long avg2 = total - currSum;
            if (i != n - 1)
                avg2 /= (n - i - 1);

            int diff = int(abs(avg1 - avg2));
            if (diff < mini)
            {
                mini = diff;
                ans = i;
            }
        }
        return ans;
    }
};
