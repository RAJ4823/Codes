// Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-resultant-array-after-removing-anagrams
 *  RUNTIME: 11 ms
 *  MEMORY: 14.8 MB
 *  DATE: 12-16-2023, 6:36:41 PM
 *
 */

// Solution:

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<int> count1(26, 0), count2(26, 0);
        vector<string> ans;
        bool check = true;

        for (string a: words) {
            check = true;
            count2 = vector<int>(26, 0);

            for (char c: a) 
                count2[c - 'a']++;
            
            for (int i = 0; i < 26; i++) {
                if (count1[i] != count2[i]) {
                    check = false;
                    break;
                }
            }
            
            if (!check) {
                ans.push_back(a);
                count1 = count2;
            }
        }
        return ans;
    }
};
