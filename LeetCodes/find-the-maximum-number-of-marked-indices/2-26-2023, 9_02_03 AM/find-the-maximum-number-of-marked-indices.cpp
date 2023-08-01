// Link: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-maximum-number-of-marked-indices
 *  RUNTIME: 172 ms
 *  MEMORY: 60.2 MB
 *  DATE: 2-26-2023, 9:02:03 AM
 *
 */

// Solution:

class Solution {
public:
    int find(vector<int> &nums, int n) {
        int i = 0;
        int j = (n + 1) / 2;
        while (j < n)
        {
            if(nums[j++] < nums[i] * 2) continue;
            i++;
        }
        return i * 2;
    }

    int maxNumOfMarkedIndices(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return find(nums, n);
    }
};
