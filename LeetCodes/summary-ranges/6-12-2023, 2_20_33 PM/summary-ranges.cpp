// Link: https://leetcode.com/problems/summary-ranges

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: summary-ranges
 *  RUNTIME: 0 ms
 *  MEMORY: 7 MB
 *  DATE: 6-12-2023, 2:20:33 PM
 *
 */

// Solution:

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.empty()) return {};
        
        vector<string> ans;
        int n = nums.size(), i = 0;
        int start = nums[0], end = nums[0];
        for(int i=0; i<n; i++) {
            if(end + 1 < nums[i]) {
                if(start == end) 
                    ans.push_back(to_string(start));
                else
                    ans.push_back(to_string(start) + "->" + to_string(end));

                start = nums[i];
                end = nums[i];
            } else {
                end = nums[i];
            }
        }
        if(start == end) 
            ans.push_back(to_string(start));
        else
            ans.push_back(to_string(start) + "->" + to_string(end));
        return ans;
    }
};
