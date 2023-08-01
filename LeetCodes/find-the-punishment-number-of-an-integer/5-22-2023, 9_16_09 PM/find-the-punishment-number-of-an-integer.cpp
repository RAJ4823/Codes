// Link: https://leetcode.com/problems/find-the-punishment-number-of-an-integer

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: find-the-punishment-number-of-an-integer
 *  RUNTIME: 223 ms
 *  MEMORY: 12.8 MB
 *  DATE: 5-22-2023, 9:16:09 PM
 *
 */

// Solution:

class Solution {
public:
    unordered_map<int, int> mp;

    bool check(string &s, int val, int i){
        int num = stoi(s.substr(i));
        if(num == val) 
            return true;

        if(val > num || val < 0 || s.size() == i) 
            return false;
        
        for(int j = 1;j < s.size() - i; j++){
            if(check(s, val - stoi(s.substr(i, j)), i+j)) 
                return true;
        }
        
        return false;
    }
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            int sqr = i*i;
            string str = to_string(sqr);   
            
            if(mp.find(sqr) == mp.end()) 
                mp[sqr] = check(str, i, 0); 
            ans += sqr * mp[sqr];
        }
        return ans;
    }
};
