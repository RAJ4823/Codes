// Link: https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-score-of-an-array-after-marking-all-elements
 *  RUNTIME: 652 ms
 *  MEMORY: 134.7 MB
 *  DATE: 3-24-2023, 9:11:33 AM
 *
 */

// Solution:

class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0, n = nums.size();
        set<pair<long long,int>> s;
        for(int i=0; i<n; ++i) {
            s.insert({nums[i], i});
        }
        
        while(!s.empty()) {
            auto x = *s.begin();
            long long value = x.first;
            int index = x.second;
            score += value;
            
            int left = (index == 0) ? index : index - 1;
            int right= (index == n-1)? index: index + 1;
            
            if(s.count({nums[left], left}) > 0) s.erase({nums[left], left});
            if(s.count({nums[right], right}) > 0) s.erase({nums[right], right});
            if(s.count({nums[index], index}) > 0) s.erase({nums[index], index});
        }
        return score;
    }
};
