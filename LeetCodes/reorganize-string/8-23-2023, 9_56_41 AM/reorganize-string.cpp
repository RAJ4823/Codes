// Link: https://leetcode.com/problems/reorganize-string

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: reorganize-string
 *  RUNTIME: 0 ms
 *  MEMORY: 6.2 MB
 *  DATE: 8-23-2023, 9:56:41 AM
 *
 */

// Solution:

class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        vector<pair<int, char>> freq(26, {0, 'X'});
        for(char c: s){
            freq[c-'a'].first++;
            freq[c-'a'].second=c;
        }
 
        int max_freq=0, max_i=-1;
        for(int i=0; i<26; i++){
            if (max_freq<freq[i].first){
                max_freq=freq[i].first;
                max_i=i;
            }
        }

        swap(freq[0], freq[max_i]);
        if (max_freq>(n+1)/2) return string();
        string ans(n, 'X');

        int j=0;
        for (int i = 0; i < n; i += 2) {
            while (j < 26 && freq[j].first == 0) j++;
            ans[i] = freq[j].second;
            freq[j].first--;
        }
        
        for (int i = 1; i < n; i += 2) {
            while (j < 26 && freq[j].first == 0) j++;
             ans[i] = freq[j].second;
            freq[j].first--;
        }

        return ans;    
    }
};
