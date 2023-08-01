// Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: smallest-subsequence-of-distinct-characters
 *  RUNTIME: 0 ms
 *  MEMORY: 6.3 MB
 *  DATE: 1-17-2023, 10:27:14 AM
 *
 */

// Solution:

class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, bool> vis;
        unordered_map<char, int > cnt;
        string ans;

        for(char ch : s) cnt[ch]++, vis[ch] = false;
        for(char ch : s) {
            cnt[ch]--;
            if(!vis[ch]) {
                while(!ans.empty() && (ans.back() > ch && cnt[ans.back()])){
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
