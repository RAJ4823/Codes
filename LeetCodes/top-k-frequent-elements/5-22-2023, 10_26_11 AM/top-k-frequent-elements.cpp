// Link: https://leetcode.com/problems/top-k-frequent-elements

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: top-k-frequent-elements
 *  RUNTIME: 59 ms
 *  MEMORY: 19 MB
 *  DATE: 5-22-2023, 10:26:11 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> cnt;
        map<int,set<int>> freq;

        for(auto &val: nums) {
            cnt[val]--;
            int x = cnt[val];
            freq[x+1].erase(val);
            freq[x].insert(val);
        }

        vector<int> ans;
        for(auto &x: freq) {
            for(auto &val: x.second) {
                if(ans.size() < k) {
                    ans.push_back(val);
                }
            }
        }
        return ans;
    }
};
