// Link: https://leetcode.com/problems/form-smallest-number-from-two-digit-arrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: form-smallest-number-from-two-digit-arrays
 *  RUNTIME: 5 ms
 *  MEMORY: 22.1 MB
 *  DATE: 4-1-2023, 8:12:46 PM
 *
 */

// Solution:

class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> cnt1, cnt2;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(auto &val: nums1) {
            cnt1[val]++;
        }
        for(auto &val: nums2) {
            cnt2[val]++;
        }
        
        int mini = INT_MAX;
        for(auto &x: cnt1) {
            if(cnt2[x.first] > 0) {
                mini = min(x.first, mini);
            }
        }
        
        int num = min(nums1[0], nums2[0]) * 10 + max(nums1[0], nums2[0]);
        return min(mini, num);
    }
};
