// Link: https://leetcode.com/problems/find-k-pairs-with-smallest-sums

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-k-pairs-with-smallest-sums
 *  RUNTIME: 384 ms
 *  MEMORY: 109.8 MB
 *  DATE: 6-27-2023, 9:59:39 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>> pq;

        int end = false;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int sum = nums1[i] + nums2[j];
                if(pq.size() < k) {
                    pq.push({sum, {nums1[i], nums2[j]}}); 
                } else if(sum < pq.top().first) {
                    pq.pop();
                    pq.push({sum, {nums1[i], nums2[j]}});
                } else {
                    break;
                }
            }
        }
        while(!pq.empty()) {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};
