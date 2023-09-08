// Link: https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimize-the-maximum-difference-of-pairs
 *  RUNTIME: 143 ms
 *  MEMORY: 81 MB
 *  DATE: 8-9-2023, 12:41:03 PM
 *
 */

// Solution:

class Solution {
public:
    bool isPossible(vector<int>& nums, int diff, int p) {
        int count = 0;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i+1] - nums[i] <= diff) {
                count++;
                i++;
            }
        }
        return (count >= p);
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int low = 0, high = nums[n-1] - nums[0];
        int ans = high;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(nums, mid, p)) {
                high = mid - 1;
                ans = min(ans, mid);
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
