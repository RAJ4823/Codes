// Link: https://leetcode.com/problems/make-number-of-distinct-characters-equal

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: make-number-of-distinct-characters-equal
 *  RUNTIME: 59 ms
 *  MEMORY: 16.6 MB
 *  DATE: 7-3-2023, 9:22:49 AM
 *
 */

// Solution:

class Solution {
public:
    bool isItPossible(string word1, string word2) 
    {
        vector<int>cnt1(26,0); 
        vector<int>cnt2(26,0);

        int n1=0;
        int n2=0; 

        for(int i =0;i<word1.size();i++) 
        {
            cnt1[word1[i]-'a']++;
            if(cnt1[word1[i]-'a']==1) n1++;
        }

        for(int i =0;i<word2.size();i++) 
        {
            cnt2[word2[i]-'a']++;
            if(cnt2[word2[i]-'a']==1) n2++;
        }

        for(int i =0;i<26;i++)
        {
            for(int j =0;j<26;j++)
            {
                if(cnt1[i]!=0 && cnt2[j]!=0 && i!=j)
                {
                    if(cnt2[j]==1) n2--; 
                    if(cnt2[i]==0) n2++;
                    if(cnt1[j]==0) n1++; 
                    if(cnt1[i]==1) n1--; 
                    if(n1==n2) return true;
                    if(cnt2[i]==0) n2--;
                    if(cnt2[j]==1) n2++;
                    if(cnt1[j]==0) n1--;
                    if(cnt1[i]==1) n1++;
                }
                if(cnt1[i]!=0 && cnt2[j]!=0 && i==j)
                {
                    if(n1==n2) return true;
                }
            }
        }
        
        return false;
    }
};
