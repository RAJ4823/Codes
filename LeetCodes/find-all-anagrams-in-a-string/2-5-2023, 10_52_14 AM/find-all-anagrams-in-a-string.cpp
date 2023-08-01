// Link: https://leetcode.com/problems/find-all-anagrams-in-a-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-all-anagrams-in-a-string
 *  RUNTIME: 15 ms
 *  MEMORY: 8.7 MB
 *  DATE: 2-5-2023, 10:52:14 AM
 *
 */

// Solution:


        



class Solution {

public:

    vector<int> findAnagrams(string s, string p) {

        int m = s.size(), n = p.size();

        if(m < n) return {};

        vector<int> count1(26, 0), count2(26, 0), ans;

        for(auto &ch: p) count1[ch - 'a']++;

        

        int i = 0, j = 0;

        while(j < n) 

            count2[s[j++] - 'a']++;

        if(count1 == count2)

            ans.push_back(0);

        

        while(j < m) {

            count2[s[j++] - 'a']++;

            count2[s[i++] - 'a']--;

            if(count1 == count2)

                ans.push_back(i);

        }

        return ans;

    }

};
