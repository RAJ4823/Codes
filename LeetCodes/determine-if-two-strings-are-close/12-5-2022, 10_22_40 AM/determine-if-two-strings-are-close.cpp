// Link: https://leetcode.com/problems/determine-if-two-strings-are-close

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: determine-if-two-strings-are-close
 *  RUNTIME: 170 ms
 *  MEMORY: 21.3 MB
 *  DATE: 12-5-2022, 10:22:40 AM
 *
 */

// Solution:

class Solution {
public:
    bool closeStrings(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n != m)
            return false;
        map<char,int> ms, mt;
        multiset<int> s1, s2;
        multiset<char> c1,c2;
        for(int i=0; i<n; i++)
        {
            ms[s[i]]++;
            mt[t[i]]++;
        }
        for(auto x:ms) c1.insert(x.first), s1.insert(x.second);
        for(auto x:mt) c2.insert(x.first), s2.insert(x.second);

        return (c1 == c2 && s1 == s2);
    }
};
