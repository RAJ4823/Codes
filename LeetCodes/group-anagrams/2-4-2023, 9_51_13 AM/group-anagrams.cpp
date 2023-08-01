// Link: https://leetcode.com/problems/group-anagrams

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: group-anagrams
 *  RUNTIME: 39 ms
 *  MEMORY: 20.7 MB
 *  DATE: 2-4-2023, 9:51:13 AM
 *
 */

// Solution:

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        int n = strs.size();
        for(auto &str: strs) {
            string original = str;
            sort(str.begin(), str.end());
            m[str].push_back(original);
        }

        vector<vector<string>> ans;
        for(auto [str, vec]: m) {
            ans.push_back(vec);
        }
        return ans;
    }
};
