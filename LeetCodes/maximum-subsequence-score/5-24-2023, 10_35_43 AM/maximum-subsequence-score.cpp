// Link: https://leetcode.com/problems/maximum-subsequence-score

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-subsequence-score
 *  RUNTIME: 306 ms
 *  MEMORY: 92 MB
 *  DATE: 5-24-2023, 10:35:43 AM
 *
 */

// Solution:

#define ll long long
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<pair<int,int>> v;
        priority_queue<int, vector<int>, greater<>> pq;

        for(int i = 0; i < n; i++) {
            v.push_back({nums2[i], nums1[i]});
        }
        sort(v.rbegin(), v.rend());  
        ll sum = 0, ans = 0;
        for(int i = 0; i < k-1; i++) {
            sum += v[i].second;
            pq.push(v[i].second);
        }

        for(int i = k-1; i < n; i++) {
            sum += v[i].second;
            ans = max(ans, sum * v[i].first);

            pq.push(v[i].second);
            sum -= pq.top();
            pq.pop();
        }
        return ans;
    }
};
