// Link: https://leetcode.com/problems/fair-distribution-of-cookies

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: fair-distribution-of-cookies
 *  RUNTIME: 1669 ms
 *  MEMORY: 6.9 MB
 *  DATE: 7-1-2023, 8:33:02 AM
 *
 */

// Solution:

class Solution {
public:
    int find(int i, vector<int> &cookies, vector<int> &store) {
        if(i >= cookies.size()) {
            int res = 0;
            for(auto &val: store) res = max(res, val);
            return res;
        }

        int ans = INT_MAX;
        for(int j=0; j<store.size(); j++) {
            store[j] += cookies[i];
            ans = min(ans, find(i+1, cookies, store));
            store[j] -= cookies[i];
        }
        return ans;
    }
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> store(k, 0);
        return find(0, cookies, store);
    }
};
