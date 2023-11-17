// Link: https://leetcode.com/problems/find-unique-binary-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-unique-binary-string
 *  RUNTIME: 0 ms
 *  MEMORY: 10.4 MB
 *  DATE: 11-16-2023, 11:09:42 AM
 *
 */

// Solution:

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        for(int i=0; i<nums.size(); i++) {
            ans += (nums[i][i] == '0') ? '1' : '0';
        }
        return ans;
    }
};
