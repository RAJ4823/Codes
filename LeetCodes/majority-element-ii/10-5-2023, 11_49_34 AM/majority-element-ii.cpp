// Link: https://leetcode.com/problems/majority-element-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: majority-element-ii
 *  RUNTIME: 17 ms
 *  MEMORY: 16.4 MB
 *  DATE: 10-5-2023, 11:49:34 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        vector<int> ans;

        int minFreq = nums.size() / 3;

        for(auto &val: nums) {
            freq[val]++;
        }
        for(auto &[val, cnt]: freq) {
            if(cnt > minFreq) {
                ans.push_back(val);
            }
        }
        return ans;
    }
};
