// Link: https://leetcode.com/problems/buddy-strings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: buddy-strings
 *  RUNTIME: 9 ms
 *  MEMORY: 6.9 MB
 *  DATE: 7-3-2023, 8:59:50 AM
 *
 */

// Solution:

class Solution {
public:
    bool buddyStrings(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> cnt;
        int max_cnt = 0;
        int p = -1;
        for(int i=0; i<s.length(); i++) {
            if(s[i] != t[i]) {
                if(p == -1) p = i;
                else {
                    swap(s[i], s[p]);
                    break;
                }
            }
            cnt[s[i]]++;
            max_cnt = max(max_cnt, cnt[s[i]]);
        }

        if(s == t) {
            if(p == -1) return max_cnt >= 2;
            return true;
        }
        return false;
    }
};
