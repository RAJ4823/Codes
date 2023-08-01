// Link: https://leetcode.com/problems/detect-capital

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: detect-capital
 *  RUNTIME: 0 ms
 *  MEMORY: 6.1 MB
 *  DATE: 1-2-2023, 5:08:27 PM
 *
 */

// Solution:

class Solution {
public:
    bool detectCapitalUse(string word) {
        bool first = true;
        if('a' <= word[0] && word[0] <= 'z')
            first = false;
        
        int upper = 0, lower = 0;
        int n = word.size();
        for(int i = 0; i< n; i++) {
            if('a' <= word[i] && word[i] <= 'z')
                lower++;    
            else
                upper++;
        }

        if(first && (upper == n || lower == n-1)) 
            return true;
        if(!first && upper == 0)
            return true;
        return false;
    }
};
