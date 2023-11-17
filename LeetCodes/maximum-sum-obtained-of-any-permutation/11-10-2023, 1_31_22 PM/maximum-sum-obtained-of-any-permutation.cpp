// Link: https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-sum-obtained-of-any-permutation
 *  RUNTIME: 347 ms
 *  MEMORY: 128.7 MB
 *  DATE: 11-10-2023, 1:31:22 PM
 *
 */

// Solution:

class Solution {
public:
    vector<int> getMaxPermutation(vector<int> &nums, vector<vector<int>> &reqs) {
        int n = nums.size(), m = reqs.size();

        // Count index frequencies in requests
        vector<int> count(n+1, 0);
        for(auto &req: reqs) {
            count[req[0]]++;
            count[req[1] + 1]--;
        }

        vector<pair<int,int>> pq;
        for(int i=0; i<n; i++) {
            pq.push_back({count[i], i}); 
            count[i+1] += count[i];
        }

        sort(pq.begin(), pq.end(), [&](const pair<int,int> &a, const pair<int,int> &b) {
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        sort(nums.begin(), nums.end());

        // Make permutation that will give max total
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            arr[pq[i].second] = nums[i];
        }
        return arr;
    }

    
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& reqs) {
        int n = nums.size();
        nums = getMaxPermutation(nums, reqs);

        vector<int> suff(n + 1, 0);
        for(int i=1; i<=n; i++) {
            suff[i] = suff[i-1] + nums[i-1];
        }

        long long sum = 0, mod = 1e9+7;
        for(auto &req: reqs) {
            long long rangeSum = suff[req[1]+1] - suff[req[0]];
            sum = (sum % mod + rangeSum % mod) % mod;
        }
        return sum;
    }
};
