// Link: https://leetcode.com/problems/permutation-in-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: permutation-in-string
 *  RUNTIME: 8 ms
 *  MEMORY: 7.4 MB
 *  DATE: 2-4-2023, 9:31:02 AM
 *
 */

// Solution:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if(m < n) return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        for(auto &ch: s1) count1[ch - 'a']++;
        
        int i = 0, j = 0;
        while(j < n) 
            count2[s2[j++] - 'a']++;

        while(j < m && count1 != count2) {
            count2[s2[j++] - 'a']++;
            count2[s2[i++] - 'a']--;
        }
        if(count1 == count2) return true;

        return false;
    }
};
