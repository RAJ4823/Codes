// Link: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: minimum-deletions-to-make-character-frequencies-unique
 *  RUNTIME: 78 ms
 *  MEMORY: 17.5 MB
 *  DATE: 9-12-2023, 9:20:03 AM
 *
 */

// Solution:

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> fc;
        unordered_set<int> vis;
        int del = 0;

        for(auto &ch: s) {
            fc[ch]++;
        }

        for(auto &x: fc) {
            int freq = x.second;
            while(freq && vis.count(freq)) {
                freq--;
                del++;
            }
            vis.insert(freq);
        }
        
        return del;
    }
};
