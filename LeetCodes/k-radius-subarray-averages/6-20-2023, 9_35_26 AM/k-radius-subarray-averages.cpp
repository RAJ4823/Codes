// Link: https://leetcode.com/problems/k-radius-subarray-averages

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: k-radius-subarray-averages
 *  RUNTIME: 238 ms
 *  MEMORY: 129.9 MB
 *  DATE: 6-20-2023, 9:35:26 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        nums.push_back(0);

        vector<int> avgs(n, -1);
        if(n < 2*k) return avgs;
     
        for(int i=0; i<=2*k; i++) sum += nums[i];
        
        for(int i=k; i<n-k; i++) {
            avgs[i] = (sum) / (2*k + 1);
            sum += nums[i+k+1];
            sum -= nums[i-k];
        }
        return avgs;
    }
};
