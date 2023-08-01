// Link: https://leetcode.com/problems/successful-pairs-of-spells-and-potions

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: successful-pairs-of-spells-and-potions
 *  RUNTIME: 272 ms
 *  MEMORY: 97.2 MB
 *  DATE: 4-2-2023, 9:30:29 AM
 *
 */

// Solution:

class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long suc) {
        
        vector<int> v(s.size(),0);
        sort(p.begin(),p.end());
        
        for(int i=0;i<s.size();i++)
        {
            int h=p.size()-1;
            int l=0;
            int mid;
            while(l<=h)
            {
                mid = l + (h-l)/2;
                
                if((long long int)s[i]*(long long int)p[mid] >= suc)
                    h = mid-1;
                
                else
                    l = mid+1;
            }
            
            v[i] = p.size()-1-h;
        }
        
        return v;
    }
};
