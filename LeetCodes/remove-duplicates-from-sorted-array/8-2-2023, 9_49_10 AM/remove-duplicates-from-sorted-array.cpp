// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-duplicates-from-sorted-array
 *  RUNTIME: 7 ms
 *  MEMORY: 18.9 MB
 *  DATE: 8-2-2023, 9:49:10 AM
 *
 */

// Solution:

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> m;
        int index = 0;
        for(auto &x: nums) {
            if(m.find(x) == m.end()) {
                m[x] = index++;
            }
        }
        for(auto &x: m) {
            nums[x.second] = x.first;
        }
        for(int i=index; i<nums.size(); i++) {
            nums[i] = '_';
        }
        return index;
    }
};
