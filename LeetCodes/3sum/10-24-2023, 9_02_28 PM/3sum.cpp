// Link: https://leetcode.com/problems/3sum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: 3sum
 *  RUNTIME: 1090 ms
 *  MEMORY: 188.3 MB
 *  DATE: 10-24-2023, 9:02:28 PM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        set<vector<int>> st;

        for(int i=0; i<n-2; i++) {
            int j = i+1, k = n - 1;
            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    st.insert({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                } else if(sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return vector<vector<int>> (st.begin(), st.end());
    }
};
