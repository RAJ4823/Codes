// Link: https://leetcode.com/problems/sort-characters-by-frequency

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-characters-by-frequency
 *  RUNTIME: 7 ms
 *  MEMORY: 8.5 MB
 *  DATE: 8-18-2023, 11:08:18 AM
 *
 */

// Solution:

class Solution {
public:
    string frequencySort(string str) {
        string ans = "";
        unordered_map<char, int> count;
        map<int, vector<char>> m;

        int maxFreq = 0;
        for(auto &ch: str) {
            count[ch]++;
        }
        for(auto &x: count) {
            m[-x.second].push_back(x.first);
        }
        for(auto &x: m) {
            for(auto &ch: x.second) {
                int cnt = -x.first;
                while(cnt) {
                    ans += ch;
                    cnt--;
                }
            }
        }
        return ans;
    }
};
