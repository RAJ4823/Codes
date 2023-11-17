// Link: https://leetcode.com/problems/minimum-operations-to-collect-elements

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-operations-to-collect-elements
 *  RUNTIME: 4 ms
 *  MEMORY: 19.2 MB
 *  DATE: 11-3-2023, 5:04:02 PM
 *
 */

// Solution:

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> vals;
        int moves = 0;
        for(int i=nums.size() - 1; i>=0; i--) {
            moves++;
            if(nums[i] <= k)
                vals.insert(nums[i]);
            
            if(vals.size() == k)
                return moves;
        }
        return 0;
    }
};
