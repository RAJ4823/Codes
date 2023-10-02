// Link: https://leetcode.com/problems/remove-duplicate-letters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: remove-duplicate-letters
 *  RUNTIME: 0 ms
 *  MEMORY: 7.1 MB
 *  DATE: 9-26-2023, 10:14:28 AM
 *
 */

// Solution:

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> cnt, vis;

        for(auto &ch: s) {
            cnt[ch]++;
            vis[ch] = false;
        }

        string ans;
        for(auto &ch: s) {
            cnt[ch]--;
            if(!vis[ch]) {
                while(!ans.empty() && ans.back() > ch && cnt[ans.back()] > 0) {
                    vis[ans.back()] = false;
                    ans.pop_back();
                }
                vis[ch] = true;
                ans.push_back(ch);
            }
        }   
        return ans;
    }
};
