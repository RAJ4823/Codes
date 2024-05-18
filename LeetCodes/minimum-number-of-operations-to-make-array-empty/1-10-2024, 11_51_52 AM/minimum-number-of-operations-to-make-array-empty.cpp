// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-number-of-operations-to-make-array-empty
 *  RUNTIME: 128 ms
 *  MEMORY: 91.6 MB
 *  DATE: 1-10-2024, 11:51:52 AM
 *
 */

// Solution:

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freq;
        int operations = 0;
        for(auto &val: nums) {
            freq[val]++;
        } 
        for(auto &[val, count]: freq) {
            if(count == 1) {
                return -1;
            }

            if(count % 3 == 0) {
                operations += (count / 3);
            } else if(count % 3 == 2) {
                operations += (count / 3) + 1;
            } else {
                operations += (count - 2) / 3 + 2;
            }
        }

        return operations;
    }
};
