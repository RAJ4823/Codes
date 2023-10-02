// Link: https://leetcode.com/problems/intersection-of-two-arrays

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: intersection-of-two-arrays
 *  RUNTIME: 4 ms
 *  MEMORY: 10.5 MB
 *  DATE: 9-14-2023, 11:38:18 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), i = 0, j = 0;
        vector<int> ans;
        set<int> st;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while(i<m && j<n){
            if(nums1[i]<nums2[j]) 
                i++;
            else if(nums1[i]>nums2[j]) 
                j++;
            else {
                st.insert(nums1[i]);
                i++;
                j++;
            }
        }
   
        for(auto val: st)
           ans.push_back(val);

    return ans;
}
};
