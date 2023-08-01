// Link: https://leetcode.com/problems/arithmetic-slices

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: arithmetic-slices
 *  RUNTIME: 0 ms
 *  MEMORY: 7.2 MB
 *  DATE: 3-21-2023, 8:48:32 AM
 *
 */

// Solution:

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        // vector<int> diff(n);
        if(n == 1) return 0;
        int diff = nums[1] - nums[0], same = 1, count = 0;

        for(int i=1; i<n-1; i++) {
            // diff[i] = nums[i+1] - nums[i];
            if(nums[i+1] - nums[i] == diff) {
                same++;
            } else {
                // cout << nums[i+1] << ' ' << nums[i] << " = " << same << endl;
                count += max(0, ((same - 1)*same)/2);
                diff = nums[i+1] - nums[i];
                same = 1;
            }
        }
        count += max(0, (same*(same - 1))/2);
        return count;
    }
};
