// Link: https://leetcode.com/problems/happy-students

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: happy-students
 *  RUNTIME: 87 ms
 *  MEMORY: 72.1 MB
 *  DATE: 9-18-2023, 6:37:49 PM
 *
 */

// Solution:

class Solution {
public:
    int countWays(vector<int>& nums) {
        nums.push_back(-1);
        nums.push_back(INT_MAX);
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        
        for(int i=0; i<n-1; i++) {
            if(nums[i] < i && i < nums[i+1]) {
                ans++;
            }
        }
        return ans;
    }
};
