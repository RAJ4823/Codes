// Link: https://leetcode.com/problems/continuous-subarray-sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: continuous-subarray-sum
 *  RUNTIME: 245 ms
 *  MEMORY: 113.8 MB
 *  DATE: 1-19-2023, 6:32:49 PM
 *
 */

// Solution:

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum = 0, n = nums.size();

        m[0] = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (m.find(sum % k) == m.end())
                m[sum % k] = i + 1;
            else if (m[sum % k] < i)
                return true;
        }
        return false;
    }
};
