// Link: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: redistribute-characters-to-make-all-strings-equal
 *  RUNTIME: 35 ms
 *  MEMORY: 12 MB
 *  DATE: 12-30-2023, 10:25:33 AM
 *
 */

// Solution:

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> count(26, 0);
        int maxFreq = words.size();
        if(maxFreq == 1)
            return true;
            
        for(auto &word: words) {
            for(auto &ch: word) {
                count[ch - 'a']++;
            }
        }
        for(int i=0; i<26; i++) {
            if(count[i] % maxFreq != 0)
                return false;
        }
        return true;
    }
};
