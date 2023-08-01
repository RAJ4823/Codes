// Link: https://leetcode.com/problems/naming-a-company

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: naming-a-company
 *  RUNTIME: 838 ms
 *  MEMORY: 79.1 MB
 *  DATE: 2-9-2023, 9:50:06 AM
 *
 */

// Solution:

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long count = 0;
        long long cnt[26][26]={0};
        unordered_set<string> st(ideas.begin(), ideas.end());
        
        for(auto s: st){
            int k = s[0] - 'a';
            
            for(int i = 0;i < 26; i++)
            {
                s[0] = i + 'a';
                if (st.find(s)==st.end())
                {
                    cnt[k][i]++;  
                    count += cnt[i][k];
                }
            }
        }
        return count*2;
   }
};
