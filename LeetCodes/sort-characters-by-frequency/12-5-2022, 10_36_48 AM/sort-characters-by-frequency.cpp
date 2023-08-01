// Link: https://leetcode.com/problems/sort-characters-by-frequency

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: sort-characters-by-frequency
 *  RUNTIME: 37 ms
 *  MEMORY: 8 MB
 *  DATE: 12-5-2022, 10:36:48 AM
 *
 */

// Solution:

class Solution {
public:
    string frequencySort(string str) {
        map<char,int> m;
        multimap<int,char> mp;
        int i = str.size()-1;
        for(int i=0; i<str.size(); i++)   m[str[i]]++;
        for(auto x:m) mp.insert({x.second, x.first});

        for(auto x:mp)
        {
            int freq = x.first;
            char ch = x.second;
            while(freq--)
                str[i--] = ch;
        }
        return str;
    }
};
