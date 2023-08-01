// Link: https://leetcode.com/problems/frequency-tracker

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: frequency-tracker
 *  RUNTIME: 633 ms
 *  MEMORY: 211.7 MB
 *  DATE: 5-7-2023, 8:37:45 AM
 *
 */

// Solution:

class FrequencyTracker {
public:
    unordered_map<int,int> cnt;
    unordered_map<int,set<int>> freq;
    
    FrequencyTracker() {}
    
    void add(int number) {
        cnt[number]++;
        int f = cnt[number];
        freq[f-1].erase(number);
        freq[f].insert(number);
    }
    
    void deleteOne(int number) {
        if(cnt.find(number) != cnt.end()) {
            if(cnt[number] == 0)
                    return;
            cnt[number]--;
            int f = cnt[number];
            freq[f+1].erase(number);
            freq[f].insert(number);
        }
    }
    
    bool hasFrequency(int f) {
        if(freq.find(f) != freq.end()) {
            return (freq[f].size() > 0);
        }
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
