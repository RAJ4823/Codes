// Link: https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: maximum-number-of-achievable-transfer-requests
 *  RUNTIME: 115 ms
 *  MEMORY: 8.7 MB
 *  DATE: 7-2-2023, 9:07:13 AM
 *
 */

// Solution:

class Solution {
public:
    int ans = 0, n, m;
    void track(int i, vector<vector<int>> &reqs, vector<int> &ind, int count) {
        if(i == m) {
            for(int i=0; i<n; i++) {
                if(ind[i] != 0) return;
            }
            ans = max(ans, count);
            return;
        }

        //TAKE
        ind[reqs[i][0]]--;
        ind[reqs[i][1]]++;
        track(i + 1, reqs, ind, count + 1);

        //NOT TAKE
        ind[reqs[i][0]]++;
        ind[reqs[i][1]]--;
        track(i + 1, reqs, ind, count);
    }
    int maximumRequests(int size, vector<vector<int>>& reqs) {
        n = size;
        m = reqs.size();
        vector<int> ind(n, 0);
        track(0, reqs, ind, 0);
        return ans;
    }
};
