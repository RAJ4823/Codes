// Link: https://leetcode.com/problems/data-stream-as-disjoint-intervals

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: data-stream-as-disjoint-intervals
 *  RUNTIME: 90 ms
 *  MEMORY: 33.5 MB
 *  DATE: 1-28-2023, 9:46:42 AM
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
        if(s.empty()) return {};

        vector<vector<int>> ans;
        int start = -1, end = -1;
        for(auto &val: s) {
            if(start < 0) {
                start = end = val;
            } else if(end + 1 == val) {
                end = val;
            } else {
                ans.push_back({start, end});
                start = end = val;
            }
        }
        ans.push_back({start, end});
        
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */
