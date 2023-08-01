// Link: https://leetcode.com/problems/partition-string-into-minimum-beautiful-substrings

/** Submission Info:
 *
 *  AUTHOR: the_247 | Raj Patel
 *  TITLE: partition-string-into-minimum-beautiful-substrings
 *  RUNTIME: 3 ms
 *  MEMORY: 6.5 MB
 *  DATE: 7-12-2023, 5:08:09 PM
 *
 */

// Solution:

class Solution {
public:
    unordered_set<string> st;
    int n;
    int find(int start, string &s) {
        if(start >= n) return 0;
        
        int ans = 100;
        
        for(int i=start+1; i<=n; i++) {
            string left = s.substr(start, i - start);
            if(st.find(left) != st.end()) {
                ans = min(ans, 1 + find(i, s));
            }
        }
        return ans;
    }
    int minimumBeautifulSubstrings(string s) {
        n = s.size();
        st.insert({"11110100001001", "110000110101", "1001110001", "1111101", "11001", "101", "1"});
        int ans = find(0, s);
        if(ans == 100) return -1;
        return ans;
    }
};
