// Link: https://leetcode.com/problems/permutation-in-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: permutation-in-string
 *  RUNTIME: 2156 ms
 *  MEMORY: 132.2 MB
 *  DATE: 2-4-2023, 9:14:25 AM
 *
 */

// Solution:

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> count;
        for(auto &ch: s1) count[ch]++;
        int n =s1.size();
        int m =s2.size();
        for(int i=0; i<= m-n; i++) {
            if(count.find(s2[i]) != count.end()) {
                unordered_map<char, int> m = count;
                string substr = s2.substr(i, n);
                for(auto &ch: substr) {
                    if(m[ch] == 1) m.erase(ch);
                    else m[ch]--;
                }
                if(m.empty()) return true;
            }
        }
        return false;
    }
};
