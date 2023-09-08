// Link: https://leetcode.com/problems/sliding-window-maximum

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sliding-window-maximum
 *  RUNTIME: 775 ms
 *  MEMORY: 175.5 MB
 *  DATE: 8-16-2023, 11:02:50 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> m;
        int n = nums.size();
        for(int i=0; i<k; i++) {
            m[-nums[i]]++;
        }
        for(int i=k; i<=n; i++) {
            auto curr = (*m.begin());
            auto prev = -nums[i-k];
            ans.push_back(-curr.first);
            cout << (-curr.first) << ' ';

            if(m[prev] == 1) {
                m.erase(prev);
            } else {
                m[prev]--;
            }
            if(i < n)
            m[-nums[i]]++;
        }
        return ans;
    }
};
