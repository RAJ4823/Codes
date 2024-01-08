// Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-resultant-array-after-removing-anagrams
 *  RUNTIME: 16 ms
 *  MEMORY: 16.6 MB
 *  DATE: 12-16-2023, 6:35:40 PM
 *
 */

// Solution:

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);

        for(int i=1;i<words.size();i++) {
            vector<int> count1(26, 0), count2(26, 0);
            for(auto &ch: words[i])
                count1[ch - 'a']++;
            for(auto &ch: words[i-1])
                count2[ch - 'a']++;
            
            if(count1 != count2)
                ans.push_back(words[i]);
        }
        return ans;
    }
};
