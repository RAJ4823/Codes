// Link: https://leetcode.com/problems/roman-to-integer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: roman-to-integer
 *  RUNTIME: 4 ms
 *  MEMORY: 7.8 MB
 *  DATE: 1-31-2023, 10:32:43 AM
 *
 */

// Solution:

class Solution {
public:
    int romanToInt(string s) {
       if (s.empty()) return 0;
        
        unordered_map<char, int> mp = {{'I', 1},{'V', 5},{'X', 10},{'L', 50},{'C', 100},{'D', 500},{'M', 1000}};
        int num = 0;
        for (int i = 0; i < s.length() - 1; ++i) {
            if (mp[s[i]] < mp[s[i + 1]]) {
                num -= mp[s[i]];
            } else {
                num += mp[s[i]];
            }
        }
        num += mp[s.back()];

        return num;
    }
};
