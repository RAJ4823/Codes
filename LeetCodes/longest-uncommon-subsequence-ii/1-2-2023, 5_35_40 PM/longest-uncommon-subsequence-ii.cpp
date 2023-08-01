// Link: https://leetcode.com/problems/longest-uncommon-subsequence-ii

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: longest-uncommon-subsequence-ii
 *  RUNTIME: 7 ms
 *  MEMORY: 8.5 MB
 *  DATE: 1-2-2023, 5:35:40 PM
 *
 */

// Solution:

class Solution {
public:
    static bool cmp(string& a, string& b) {
        return a.size() > b.size();
    }
    
    bool check(string s1, string s2) {
        int i = 0, j = 0;
        while (i < s1.size() && j < s2.size()) {
            if (s1[i] == s2[j]) 
                i++; 
            j++;
        }
        return (i == s1.size());
    }
    
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), cmp);
        unordered_map<string, int> count;
        for (auto str : strs) count[str]++;

        for (int i = 0; i < strs.size(); i++) {
            if (count[strs[i]] > 1) continue;
            bool flag = true;
            for (int j = 0; j < i; j++) {
                if(check(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            // cout << i << ' ' << flag << endl;
            if(flag) return strs[i].size();
        }
        return -1;
    }
};

