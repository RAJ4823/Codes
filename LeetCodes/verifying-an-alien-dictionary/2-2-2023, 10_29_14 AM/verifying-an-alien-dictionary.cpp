// Link: https://leetcode.com/problems/verifying-an-alien-dictionary

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: verifying-an-alien-dictionary
 *  RUNTIME: 8 ms
 *  MEMORY: 10 MB
 *  DATE: 2-2-2023, 10:29:14 AM
 *
 */

// Solution:

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        char alpha[26];
        int n = words.size();
        for(int i =0; i<26; i++) {
            alpha[order[i]-'a'] = i + 'a';
        }

        vector<string> strs;
        for(int i=0; i<n; i++){
            for(int j=0; j<words[i].size(); j++) {
                words[i][j] = alpha[words[i][j] - 'a'];
            }
            strs.push_back(words[i]);
        }
        
        sort(strs.begin(), strs.end());
        if(strs == words) return true;
        return false;
    }
};
