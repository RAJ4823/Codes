// Link: https://leetcode.com/problems/sliding-window-maximum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sliding-window-maximum
 *  RUNTIME: 514 ms
 *  MEMORY: 175.5 MB
 *  DATE: 8-16-2023, 11:07:27 AM
 *
 */

// Solution:

class Solution {
public:
    void remove(map<int,int> &m, int &val) {
        if(m[-val] == 1) {
            m.erase(-val);
        } else {
            m[-val]--;
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> m;
        int n = nums.size();
        nums.push_back(0);
        for(int i=0; i<=n; i++) {
            if(i >= k) {
                ans.push_back(-(*m.begin()).first);
                remove(m, nums[i-k]);
            }
            m[-nums[i]]++;
        }
        return ans;
    }
};
