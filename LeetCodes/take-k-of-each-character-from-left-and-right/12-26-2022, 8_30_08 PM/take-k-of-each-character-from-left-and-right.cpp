// Link: https://leetcode.com/problems/take-k-of-each-character-from-left-and-right

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: take-k-of-each-character-from-left-and-right
 *  RUNTIME: 85 ms
 *  MEMORY: 10.7 MB
 *  DATE: 12-26-2022, 8:30:08 PM
 *
 */

// Solution:

class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        int ans = n;
        unordered_map<char,int> count;

        for(int i=0;i<n;i++){
            count[s[i]]++;
        }
        if(count['a']<k || count['b']<k || count['c']<k)
                return -1;

        int i=n-1,j=n-1;
        while(i>=0){
            count[s[i]]--;
            while(count[s[i]]<k){
                count[s[j]]++;
                j--;
            }
            ans=min(ans, i - j + n - 1); 
            i--;
        }
        return ans;
    }
};
