// Link: https://leetcode.com/problems/132-pattern

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: 132-pattern
 *  RUNTIME: 60 ms
 *  MEMORY: 49 MB
 *  DATE: 9-30-2023, 10:36:08 AM
 *
 */

// Solution:

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int> s;
        int third = INT_MIN;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < third) return true;
            while (!s.empty() && s.top() < nums[i]) {
                third = s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};
