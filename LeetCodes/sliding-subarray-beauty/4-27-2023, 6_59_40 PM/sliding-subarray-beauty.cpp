// Link: https://leetcode.com/problems/sliding-subarray-beauty

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sliding-subarray-beauty
 *  RUNTIME: 584 ms
 *  MEMORY: 179.3 MB
 *  DATE: 4-27-2023, 6:59:40 PM
 *
 */

// Solution:

class Solution {
public:
    int find(vector<int> &count, int x) {
        int val = 100, k = 0;
        for(int j=0; j<=100; j++) {
            k += count[j];
            if(k >= x) {
                val = j - 50;
                break;
            }
        }
        return min(val, 0);
    }
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> count(101, 0);
        vector<int> ans(n - k + 1);

        for(int i=0; i<k; i++) {
            count[nums[i] + 50]++;
        }
        ans[0] = find(count, x);
        
        for(int i=k; i<n; i++) {
            count[nums[i - k] + 50]--;
            count[nums[i] + 50]++;
            ans[i - k + 1] = find(count, x);
        }
        return ans;
    }
};
