// Link: https://leetcode.com/problems/decode-the-message

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: decode-the-message
 *  RUNTIME: 0 ms
 *  MEMORY: 7.2 MB
 *  DATE: 9-13-2023, 9:20:50 AM
 *
 */

// Solution:

class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, char> mp;
        char alpha = 'a';
        for(auto &ch: key) {
            if(ch != ' ' && mp.find(ch) == mp.end()) {
                mp[ch] = alpha;
                alpha++;
            }
        }

        string decoded;
        for(auto &ch: message) {
            if(ch == ' ') {
                decoded += ch;
            } else {
                decoded += mp[ch];
            }
        }
        return decoded;
    }
};
