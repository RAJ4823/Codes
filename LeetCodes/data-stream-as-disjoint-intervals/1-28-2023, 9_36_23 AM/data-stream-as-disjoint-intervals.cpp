// Link: https://leetcode.com/problems/data-stream-as-disjoint-intervals

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: data-stream-as-disjoint-intervals
 *  RUNTIME: 1439 ms
 *  MEMORY: 172.5 MB
 *  DATE: 1-28-2023, 9:36:23 AM
 *
 */

// Solution:

class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {}
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        for(auto &val: s) {
            if(!ans.empty() && ans.back()[1] + 1 == val) {
                int prev = ans.back()[0];
                ans.pop_back();
                ans.push_back({prev, val});
            } else {
                ans.push_back({val, val});
            }
        }
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
